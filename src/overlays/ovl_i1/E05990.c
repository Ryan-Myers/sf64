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

s32 func_i1_80198DCC(Object_58* obj58, f32 x, f32 y) {
    Object_58* obj58;
    s32 i;

    for (i = 0, obj58 = gObjects58; i < 200;) {
        if ((obj58->obj.status == 2) &&
            (fabsf(obj58->obj.pos.x - (obj58->obj.pos.x + ((x * 650.0f) + 350.0f))) < 1200.0f) &&
            (fabsf(obj58->obj.pos.z - (obj58->obj.pos.z + ((y * 650.0f) + 350.0f))) < 1200.0f) &&
            (obj58->obj.pos.y < 650.0f)) {
            return 1;
        }
        obj58++;
        if ((obj58->obj.status == 2) &&
            (fabsf(obj58->obj.pos.x - (obj58->obj.pos.x + ((x * 650.0f) + 350.0f))) < 1200.0f) &&
            (fabsf(obj58->obj.pos.z - (obj58->obj.pos.z + ((y * 650.0f) + 350.0f))) < 1200.0f) &&
            (obj58->obj.pos.y < 650.0f)) {
            return 1;
        }
        obj58++;
        if ((obj58->obj.status == 2) &&
            (fabsf(obj58->obj.pos.x - (obj58->obj.pos.x + ((x * 650.0f) + 350.0f))) < 1200.0f) &&
            (fabsf(obj58->obj.pos.z - (obj58->obj.pos.z + ((y * 650.0f) + 350.0f))) < 1200.0f) &&
            (obj58->obj.pos.y < 650.0f)) {
            return 1;
        }
        obj58++;
        if ((obj58->obj.status == 2) &&
            (fabsf(obj58->obj.pos.x - (obj58->obj.pos.x + ((x * 650.0f) + 350.0f))) < 1200.0f) &&
            (fabsf(obj58->obj.pos.z - (obj58->obj.pos.z + ((y * 650.0f) + 350.0f))) < 1200.0f) &&
            (obj58->obj.pos.y < 650.0f)) {
            return 1;
        }
        obj58++;
        i += 4;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/overlays/ovl_i1/E05990/func_i1_80199024.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/overlays/ovl_i1/E05990/func_i1_8019949C.s")
