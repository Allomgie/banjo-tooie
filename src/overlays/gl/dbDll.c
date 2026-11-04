// Two hidden mechanisms: a key stream derived from the CIC chip that decrypts type-10 assets,
// and entry points that copy anti-tamper result bits into game flags.
#include "common.h"

extern OSMesgQueue *func_80016928(void);
extern void func_80016934(s32);
extern void cic_send_challenge();
extern void cic_read_response(OSMesgQueue *);
extern void *heap_alloc(s32);
extern u8 D_80079D70[];

// CIC challenge/response key stream and XOR decryption of type-10 assets.
// Sends a 14-byte challenge built from the 16-bit seed to the CIC and reads the
// 16-byte response into response.
void func_80800000_gldbDll(u8 *response, s32 seed)
{
    s32 i;
    u8 challenge[16];
    OSMesgQueue *queue;
    u16 word;

    queue = func_80016928();
    for (i = 0; i < 14; i += 2) {
        word = (seed >> i) | (seed << (16 - i));
        challenge[i] = word;
        challenge[i + 1] = word & 0xFF00;
    }
    challenge[14] = 0;
    challenge[15] = 2;
    for (i = 0; i < 16; i++) {
        response[i] = 0;
    }
    func_80016934(5);
    cic_send_challenge(challenge, queue);
    osRecvMesg(queue, NULL, OS_MESG_BLOCK);
    cic_read_response(queue);
    osRecvMesg(queue, NULL, OS_MESG_BLOCK);
    func_8001E170(response);
    func_80016934(0);
}

// XORs buf with the 14-byte key stream derived from seed.
void func_808000E8_gldbDll(u8 *buf, s32 seed, s32 size)
{
    u8 key[14];
    s32 i;
    func_80800000_gldbDll(key, seed);
    for (i = 0; i < size; i++)
        buf[i] = buf[i] ^ key[i % 14];
}

// Asset loader for encrypted assets: reads and decrypts the asset, unpacks it into
// a new heap buffer and stores the unpacked size in *out_size.
void *gldbDll_entrypoint_0(s32 asset_id, s32 *out_size)
{
    s32 *data;
    s32 aligned_size;
    s32 size;

    aligned_size = func_800D5DB8(asset_id);
    size = aligned_size;
    if (aligned_size & 1) {
        aligned_size++;
    }
    data = heap_alloc(aligned_size);
    rom_dma_read(data, func_800D5A6C(asset_id), aligned_size);
    func_808000E8_gldbDll(data, asset_id - 0x955, size);
    size = *data;
    size = (size >> 16) * 0x10;
    *out_size = size;
    size = (s32) heap_alloc(size);
    func_8001C2AC(data, size);
    heap_free(data);
    return (void *) size;
}

// Periodically write anti-tamper result bits into game flags.
// Passes each byte of the eeprom and reflight tamper values, plus 0x9C4, to func_800DA544.
int gldbDll_entrypoint_1()
{
    int i;
    int shift;
    // Matching: the shift temporary is needed for the match.
    for (i = 0; i < 4; i++) {
        shift = i * 8;
        func_800DA544(((int) (_gleeprom_entrypoint_0() & (0xFF << shift)) >> shift) + 0x9C4);
    }

    for (i = 0; i < 4; i++) {
        shift = i * 8;
        func_800DA544(((int) (_glreflight_entrypoint_0() & (0xFF << shift)) >> shift) + 0x9C4);
    }
}

// Copies the bits of the combined tamper value into game flags 0x648..0x64F,
// 0x660..0x667, 0x688..0x68F and 0x6A0..0x6A7.
void gldbDll_entrypoint_2(void)
{
    s32 bit;
    u32 tamper;
    u32 eeprom;

    eeprom = _gleeprom_entrypoint_0();
    tamper = (*(u32 *) (D_80079D70 + 0x1EC) | _glreflight_entrypoint_0()) | eeprom;
    for (bit = 0; bit < 8; bit++) {
        func_800DA3B8(bit + 0x648, ((1 << bit) & tamper) >> bit);
    }
    for (bit = 8; bit < 16; bit++) {
        func_800DA3B8(bit + 0x658, ((1 << bit) & tamper) >> bit);
    }
    for (bit = 16; bit < 24; bit++) {
        func_800DA3B8(bit + 0x670, ((1 << bit) & tamper) >> bit);
    }
    for (bit = 24; bit < 32; bit++) {
        func_800DA3B8(bit + 0x680, ((1 << bit) & tamper) >> bit);
    }
}

// TU-NOTE: .data is defined here in C; values are taken from the ROM.
