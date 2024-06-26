#ifndef SF64_AUDIO_EXTERNAL_H
#define SF64_AUDIO_EXTERNAL_H

#include "sys.h"
#include "audioseq_cmd.h"
#include "sfx.h"

#define AUDIO_PLAY_SFX(sfxId, srcPos, token) (Audio_PlaySfx((sfxId),(srcPos),(token),&gDefaultMod,&gDefaultMod,&gDefaultReverb))
#define AUDIO_PLAY_BGM(seqId) Audio_PlaySequence(SEQ_PLAYER_BGM, (seqId), 0, -1)
#define AUDIO_SET_SPEC(sfxLayout, spec) Audio_SetAudioSpec(0, ((sfxLayout) << 8) | (spec))
#define AUDIO_SET_SPEC_ALT(sfxLayout, spec) Audio_SetAudioSpec((sfxLayout), ((sfxLayout) << 8) | (spec))

typedef enum AudioType {
    /* 0 */ AUDIO_TYPE_MUSIC,
    /* 1 */ AUDIO_TYPE_VOICE,
    /* 2 */ AUDIO_TYPE_SFX,
} AudioType;

typedef enum {
    /* 0 */ SFXCHAN_0,
    /* 1 */ SFXCHAN_1,
    /* 2 */ SFXCHAN_2,
    /* 3 */ SFXCHAN_3
} SfxChannelLayout;

typedef enum {
    /*  0 */ AUDIOSPEC_0,
    /*  1 */ AUDIOSPEC_1,
    /*  2 */ AUDIOSPEC_2,
    /*  3 */ AUDIOSPEC_3,
    /*  4 */ AUDIOSPEC_4,
    /*  5 */ AUDIOSPEC_5,
    /*  6 */ AUDIOSPEC_6,
    /*  7 */ AUDIOSPEC_7,
    /*  8 */ AUDIOSPEC_8,
    /*  9 */ AUDIOSPEC_9,
    /* 10 */ AUDIOSPEC_10,
    /* 11 */ AUDIOSPEC_11,
    /* 12 */ AUDIOSPEC_12,
    /* 13 */ AUDIOSPEC_13,
    /* 14 */ AUDIOSPEC_14,
    /* 15 */ AUDIOSPEC_15,
    /* 16 */ AUDIOSPEC_16,
    /* 17 */ AUDIOSPEC_17,
    /* 18 */ AUDIOSPEC_18,
    /* 19 */ AUDIOSPEC_19,
    /* 20 */ AUDIOSPEC_20,
    /* 21 */ AUDIOSPEC_21,
    /* 22 */ AUDIOSPEC_22,
    /* 23 */ AUDIOSPEC_23,
    /* 24 */ AUDIOSPEC_24,
    /* 25 */ AUDIOSPEC_25,
    /* 26 */ AUDIOSPEC_26,
    /* 27 */ AUDIOSPEC_27,
    /* 28 */ AUDIOSPEC_28,
} AudioSpecID;

typedef enum {
    /* 0 */ SOUNDMODE_STEREO,
    /* 1 */ SOUNDMODE_HEADSET,
    /* 2 */ SOUNDMODE_SURROUND,
    /* 3 */ SOUNDMODE_MONO
} SoundMode;

typedef enum BgmSeqIds {
    /*  0 */ SEQ_ID_SFX,
    /*  1 */ SEQ_ID_VOICE,
    /*  2 */ SEQ_ID_CORNERIA,
    /*  3 */ SEQ_ID_METEO,
    /*  4 */ SEQ_ID_TITANIA,
    /*  5 */ SEQ_ID_SECTOR_X,
    /*  6 */ SEQ_ID_ZONESS,
    /*  7 */ SEQ_ID_AREA_6,
    /*  8 */ SEQ_ID_VENOM_1,
    /*  9 */ SEQ_ID_SECTOR_Y,
    /* 10 */ SEQ_ID_FORTUNA,
    /* 11 */ SEQ_ID_SOLAR,
    /* 12 */ SEQ_ID_BOLSE,
    /* 13 */ SEQ_ID_KATINA,
    /* 14 */ SEQ_ID_AQUAS,
    /* 15 */ SEQ_ID_SECTOR_Z,
    /* 16 */ SEQ_ID_MACBETH,
    /* 17 */ SEQ_ID_ANDROSS,
    /* 18 */ SEQ_ID_CO_BOSS_1,
    /* 19 */ SEQ_ID_ME_BOSS,
    /* 20 */ SEQ_ID_TI_BOSS,
    /* 21 */ SEQ_ID_SX_BOSS,
    /* 22 */ SEQ_ID_ZO_BOSS,
    /* 23 */ SEQ_ID_A6_BOSS,
    /* 24 */ SEQ_ID_VE_BOSS,
    /* 25 */ SEQ_ID_SY_BOSS,
    /* 26 */ SEQ_ID_UNK_26,
    /* 27 */ SEQ_ID_SO_BOSS,
    /* 28 */ SEQ_ID_BO_BOSS,
    /* 29 */ SEQ_ID_KA_BOSS,
    /* 30 */ SEQ_ID_AQ_BOSS,
    /* 31 */ SEQ_ID_SZ_BOSS,
    /* 32 */ SEQ_ID_MA_BOSS,
    /* 33 */ SEQ_ID_AND_BOSS,
    /* 34 */ SEQ_ID_TITLE,
    /* 35 */ SEQ_ID_OPENING,
    /* 36 */ SEQ_ID_MENU,
    /* 37 */ SEQ_ID_CO_INTRO,
    /* 38 */ SEQ_ID_GOOD_END,
    /* 39 */ SEQ_ID_DEATH,
    /* 40 */ SEQ_ID_GAME_OVER,
    /* 41 */ SEQ_ID_UNK_41,
    /* 42 */ SEQ_ID_ENDING,
    /* 43 */ SEQ_ID_STAR_WOLF,
    /* 44 */ SEQ_ID_INTRO_44,
    /* 45 */ SEQ_ID_INTRO_45,
    /* 46 */ SEQ_ID_VERSUS,
    /* 47 */ SEQ_ID_VS_HURRY,
    /* 48 */ SEQ_ID_CO_BOSS_2,
    /* 49 */ SEQ_ID_BAD_END,
    /* 50 */ SEQ_ID_ME_INTRO,
    /* 51 */ SEQ_ID_INTRO_51,
    /* 52 */ SEQ_ID_UNK_52,
    /* 53 */ SEQ_ID_UNK_53,
    /* 54 */ SEQ_ID_KATT,
    /* 55 */ SEQ_ID_BILL,
    /* 56 */ SEQ_ID_VS_MENU,
    /* 57 */ SEQ_ID_UNK_57,
    /* 58 */ SEQ_ID_WARP_ZONE,
    /* 59 */ SEQ_ID_UNK_59,
    /* 60 */ SEQ_ID_WORLD_MAP,
    /* 61 */ SEQ_ID_AND_BRAIN,
    /* 62 */ SEQ_ID_TO_ANDROSS,
    /* 63 */ SEQ_ID_TRAINING,
    /* 64 */ SEQ_ID_VE_CLEAR,
    /* 65 */ SEQ_ID_BOSS_RESUME,
    /* 66 */ SEQ_ID_MAX,
    /* -1 */ SEQ_ID_NONE = 0xFFFF,
} BgmSeqIds;

#define SEQ_FLAG 0x8000

extern f32 gDefaultSfxSource[];
extern f32 gDefaultMod;
extern s8 gDefaultReverb;

void Audio_PlaySfx(u32 sfxId, f32* sfxSource, u8 token, f32* freqMod, f32* volMod, s8* reverbAdd);
void Audio_KillSfxByBank(u8 bankId);
void Audio_StopSfxByBankAndSource(u8 bankId, f32* sfxSource);
void Audio_KillSfxByBankAndSource(u8 bankId, f32* sfxSource);
void Audio_KillSfxBySource(f32* sfxSource);
void Audio_KillSfxBySourceAndId(f32* sfxSource, u32 sfxId);
void Audio_KillSfxByTokenAndId(u8 token, u32 sfxId);
void Audio_KillSfxById(u32 sfxId);
void Audio_PlayVoice(s32 msgId);
void Audio_PlayVoiceWithoutBGM(u32 msgId);
void Audio_ClearVoice(void);
s32 Audio_GetCurrentVoice(void);
s32 Audio_GetCurrentVoiceStatus(void);
void Audio_SetUnkVoiceParam(u8 unkVoiceParam);
u8* Audio_UpdateFrequencyAnalysis(void);
void Audio_StartPlayerNoise(u8 playerId);
void Audio_StopPlayerNoise(u8 playerId);
void Audio_InitBombSfx(u8 playerId, u8 type);
void Audio_PlayBombFlightSfx(u8 playerId, f32* sfxSource);
void Audio_PlayBombExplodeSfx(u8 playerId, f32* sfxSource);
void Audio_StopEngineNoise(f32* sfxSource);
void Audio_SetSfxSpeedModulation(f32 vel);
void Audio_SetTransposeAndPlaySfx(f32* sfxSource, u32 sfxId, u8 semitones);
void Audio_SetModulationAndPlaySfx(f32* sfxSource, u32 sfxId, f32 freqMod);
void Audio_PlaySfxModulated(f32* sfxSource, u32 sfxId);
void Audio_SetSfxMapModulation(u8 fMod);
void Audio_SetHeatAlarmParams(u8 shields, u8 heightParam);
void Audio_PlayEventSfx(f32* sfxSource, u16 eventSfxId);
void Audio_StopEventSfx(f32* sfxSource, u16 eventSfxId);
void Audio_SetEnvSfxReverb(s8 reverb);
void Audio_SetBgmParam(s8 bgmParam);
void Audio_PlaySequence(u8 seqPlayId, u16 seqId, u8 fadeinTime, u8 bgmParam);
void Audio_PlayFanfare(u16 seqId, u8 bgmVolume, u8 bgmFadeoutTime, u8 bgmFadeinTime);
void Audio_PlayDeathSequence(void);
void Audio_PlayPauseSfx(u8 active);
void Audio_PlayMapMenuSfx(u8 active);
void Audio_SetVolume(u8 audioType, u8 volume);
void Audio_PlaySoundTest(u8 enable);
void Audio_PlaySequenceDistorted(u8 seqPlayId, u16 seqId, u16 distortion, u8 fadeinTime, u8 unused);
void Audio_PlaySoundTestTrack(u8 trackNumber);
void Audio_FadeOutAll(u8 fadeoutTime);
void Audio_KillAllSfx(void);
void Audio_SetAudioSpec(u8 unused, u16 specParam);
void Audio_PlayBgm(u16 seqId);

// used by sys or related
void AudioLoad_Init(void);
void Audio_dummy_80016A50(void);
void Audio_InitSounds(void);
void Audio_Update(void);
SPTask* AudioThread_CreateTask(void);
void AudioThread_PreNMIReset(void);


#endif
