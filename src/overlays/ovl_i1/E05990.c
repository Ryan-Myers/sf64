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

bool func_i1_80198DCC(Actor* actor, f32 x, f32 z) {
    Object_58* obj58;
    s32 i;

    for (i = 0, obj58 = gObjects58; i < 200;) {
        if ((obj58->obj.status == 2) &&
            (fabsf(obj58->obj.pos.x - (actor->obj.pos.x + ((x * 650.0f) + 350.0f))) < 1200.0f) &&
            (fabsf(obj58->obj.pos.z - (actor->obj.pos.z + ((z * 650.0f) + 350.0f))) < 1200.0f) &&
            (actor->obj.pos.y < 650.0f)) {
            return TRUE;
        }
        obj58++;
        if ((obj58->obj.status == 2) &&
            (fabsf(obj58->obj.pos.x - (actor->obj.pos.x + ((x * 650.0f) + 350.0f))) < 1200.0f) &&
            (fabsf(obj58->obj.pos.z - (actor->obj.pos.z + ((z * 650.0f) + 350.0f))) < 1200.0f) &&
            (actor->obj.pos.y < 650.0f)) {
            return TRUE;
        }
        obj58++;
        if ((obj58->obj.status == 2) &&
            (fabsf(obj58->obj.pos.x - (actor->obj.pos.x + ((x * 650.0f) + 350.0f))) < 1200.0f) &&
            (fabsf(obj58->obj.pos.z - (actor->obj.pos.z + ((z * 650.0f) + 350.0f))) < 1200.0f) &&
            (actor->obj.pos.y < 650.0f)) {
            return TRUE;
        }
        obj58++;
        if ((obj58->obj.status == 2) &&
            (fabsf(obj58->obj.pos.x - (actor->obj.pos.x + ((x * 650.0f) + 350.0f))) < 1200.0f) &&
            (fabsf(obj58->obj.pos.z - (actor->obj.pos.z + ((z * 650.0f) + 350.0f))) < 1200.0f) &&
            (actor->obj.pos.y < 650.0f)) {
            return TRUE;
        }
        obj58++;
        i += 4;
    }

    return FALSE;
}

#if 0
void func_i1_80199024(Actor* actor) {
    f32 sp5C;
    f32 sp58;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    UnkEntity28* unkEntity28;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fa1;
    f32 temp_fa1_2;
    f32 temp_ft4;
    f32 temp_fv0;
    f32 temp_fv0_3;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 var_fv0;
    f32 var_fv0_2;
    s32 temp_v0;

    if (actor->timer_0BC == 0) {
        sp58 = Rand_ZeroOne() * 1000.0f;
        sp5C = (Rand_ZeroOne() - 0.5f) * 10000.0f;
        temp_fv0 = (Rand_ZeroOne() - 0.5f) * 10000.0f;
        actor->fwork[4] = sp5C;
        actor->fwork[5] = sp58;
        actor->fwork[6] = temp_fv0;
        actor->timer_0BC = (s32) (Rand_ZeroOne() * 20.0f) + 10;
    }
    sp38 = __sinf(actor->obj.rot.x * M_DTOR);
    sp30 = __cosf(actor->obj.rot.x * M_DTOR);
    sp34 = __sinf(actor->obj.rot.y * M_DTOR);
    sp2C = __cosf(actor->obj.rot.y * M_DTOR);
    temp_fa0 = actor->fwork[4] - actor->obj.pos.x;
    sp58 = actor->fwork[5] - actor->obj.pos.y;
    temp_fa1 = actor->fwork[6] - actor->obj.pos.z;
    if (!((actor->index + gFrameCount) & 7)) {
        actor->fwork[19] = Math_RadToDeg(Math_Atan2F(temp_fa0, temp_fa1));
        actor->fwork[20] = Math_RadToDeg(Math_Atan2F(sp58, sqrtf(SQ(temp_fa0) + SQ(temp_fa1))));
    }
    var_fv0 = actor->fwork[20];
    temp_v0 = func_i1_80198DCC(actor, sp34, sp2C);
    if (temp_v0 != 0) {
        var_fv0 += 40.0f * (f32) temp_v0;
        if (var_fv0 >= 360.0f) {
            var_fv0 -= 360.0f;
        }
        if (var_fv0 < 0.0f) {
            var_fv0 += 360.0f;
        }
    } else if ((actor->obj.pos.y < (gGroundLevel + 50.0f)) && (var_fv0 > 180.0f)) {
        var_fv0 = 0.0f;
        actor->unk_0F4.x = 0.0f;
    }
    Math_SmoothStepToAngle(&actor->unk_0F4.x, var_fv0, 0.5f, 1.0f, 0.0001f);
    temp_fv1 = Math_SmoothStepToAngle(&actor->unk_0F4.y, actor->fwork[19], 0.5f, 1.0f, 0.0001f) * 30.0f;
    if (temp_fv1 < 0.0f) {
        var_fv0_2 = temp_fv1 * -1.0f;
    } else {
        var_fv0_2 = 360.0f - temp_fv1;
    }
    Math_SmoothStepToAngle(&actor->obj.rot.z, var_fv0_2, 0.1f, 3.0f, 0.01f);
    actor->obj.rot.x = -actor->unk_0F4.x;
    actor->obj.rot.y = actor->unk_0F4.y;
    temp_fv1_2 = actor->fwork[13];
    temp_fa1_2 = sp30 * 35.0f;
    temp_fa0_2 = actor->fwork[14];
    temp_ft4 = actor->fwork[12];
    actor->vel.x = temp_fv1_2 + (sp34 * temp_fa1_2);
    actor->vel.y = temp_fa0_2 + (-sp38 * 35.0f);
    actor->vel.z = temp_ft4 + (sp2C * temp_fa1_2);
    actor->fwork[13] = temp_fv1_2 - (temp_fv1_2 * 0.1f);
    actor->fwork[14] = temp_fa0_2 - (temp_fa0_2 * 0.1f);
    actor->fwork[12] = temp_ft4 - (temp_ft4 * 0.1f);
    temp_fv0_3 = gGroundLevel + 40.0f;
    if ((actor->obj.pos.y < temp_fv0_3) && (actor->vel.y < 0.0f)) {
        actor->obj.pos.y = temp_fv0_3;
        actor->vel.y = 0.0f;
    }
    func_8003088C(actor);
    unkEntity28 = &gUnkEntities28[actor->index];
    unkEntity28->unk_00 = 1;
    unkEntity28->unk_02 = (u16) actor->unk_0E4;
    unkEntity28->pos.x = actor->obj.pos.x;
    unkEntity28->pos.y = actor->obj.pos.y;
    unkEntity28->pos.z = actor->obj.pos.z;
    unkEntity28->unk_10 = actor->unk_0F4.y + 180.0f;
    if (actor->iwork[8] != 0) {
        actor->iwork[8]--;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/overlays/ovl_i1/E05990/func_i1_80199024.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/overlays/ovl_i1/E05990/func_i1_8019949C.s")
