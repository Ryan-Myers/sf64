#include "global.h"

extern ObjectInit D_6008EF8[];

void func_i1_80198C50(void) {
    Object_58* obj58;
    s32 i;

    D_80178310 = SEGMENTED_TO_VIRTUAL(D_6008EF8);
    Rand_SetSeed(1, 29000, 9876);

    obj58 = gObjects58;
    for (i = 0; i < 1000; i++) {
        if (D_80178310[i].id >= 0) {
            if (D_80178310[i].id <= 160) {
                func_800A4F4C(obj58);
                obj58->obj.status = 2;
                obj58->obj.id = D_80178310[i].id;
                obj58->obj.pos.x = D_80178310[i].xPos;
                obj58->obj.pos.z = -D_80178310[i].zPos1;
                obj58->obj.pos.y = D_80178310[i].yPos - (Rand_ZeroOneSeeded() * 300.0f);
                obj58->obj.rot.y = D_80178310[i].unk_C;
                Object_SetInfo(&obj58->info, obj58->obj.id);
                obj58++;
            }
        } else {
            break;
        }
    }
}

#if 0
s32 func_i1_80198DCC(Object_58* arg0, f32 arg1, f32 arg2) {
    Object_58* obj58;
    s32 i;

    obj58 = gObjects58;
    for (i = 0; i < 200; i++, obj58++) {
        if ((obj58->obj.status == 2) && 
                (fabsf(obj58->obj.pos.x - (arg0->obj.pos.x + ((arg1 * 650.0f) + 350.0f))) < 1200.0f) && 
                (fabsf(obj58->obj.pos.z - (arg0->obj.pos.z + ((arg2 * 650.0f) + 350.0f))) < 1200.0f) && 
                (arg0->obj.pos.y < 650.0f)) 
        {
            return 1;
        }
    }
//     var_v0 = 0;
// loop_1:
//     if ((gObjects58[i].obj.status == 2) && (fabsf(gObjects58[i].obj.pos.x - (arg0->obj.pos.x + ((arg1 * 650.0f) + 350.0f))) < 1200.0f) && (fabsf(gObjects58[i].obj.pos.z - (arg0->obj.pos.z + ((arg2 * 650.0f) + 350.0f))) < 1200.0f) && (arg0->obj.pos.y < 650.0f)) {
//         return 1;
//     }
//     temp_v1 = var_v1 + 0x58;
//     if ((gObjects58[i].unk58 == 2) && (fabsf(temp_v1->obj.pos.x - (arg0->obj.pos.x + ((arg1 * 650.0f) + 350.0f))) < 1200.0f) && (fabsf(temp_v1->obj.pos.z - (arg0->obj.pos.z + ((arg2 * 650.0f) + 350.0f))) < 1200.0f) && (arg0->obj.pos.y < 650.0f)) {
//         return 1;
//     }
//     temp_v1_2 = temp_v1 + 0x58;
//     if ((temp_v1->unk58 == 2) && (fabsf(temp_v1_2->obj.pos.x - (arg0->obj.pos.x + ((arg1 * 650.0f) + 350.0f))) < 1200.0f) && (fabsf(temp_v1_2->obj.pos.z - (arg0->obj.pos.z + ((arg2 * 650.0f) + 350.0f))) < 1200.0f) && (arg0->obj.pos.y < 650.0f)) {
//         return 1;
//     }
//     temp_v1_3 = temp_v1_2 + 0x58;
//     var_v0 += 4;
//     if ((temp_v1_2->unk58 == 2) && (fabsf(temp_v1_3->obj.pos.x - (arg0->obj.pos.x + ((arg1 * 650.0f) + 350.0f))) < 1200.0f) && (fabsf(temp_v1_3->obj.pos.z - (arg0->obj.pos.z + ((arg2 * 650.0f) + 350.0f))) < 1200.0f) && (arg0->obj.pos.y < 650.0f)) {
//         return 1;
//     }
//     var_v1 = temp_v1_3 + 0x58;
//     if (var_v0 == 0xC8) {
//         return 0;
//     }
//     goto loop_1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/overlays/ovl_i1/E05990/func_i1_80198DCC.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/overlays/ovl_i1/E05990/func_i1_80199024.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/overlays/ovl_i1/E05990/func_i1_8019949C.s")