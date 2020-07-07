#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tps_4_0 /EPS /D __EFFEKSEER_BUILD_VERSION16__=1 /Fh
//    Shader/EffekseerRenderer.ModelRenderer.ShaderTexture_PS.h
//    Shader/model_renderer_texture_PS.fx
//
//
// Buffer Definitions: 
//
// cbuffer PS_ConstanBuffer
// {
//
//   float4 fLightDirection;            // Offset:    0 Size:    16 [unused]
//   float4 fLightColor;                // Offset:   16 Size:    16 [unused]
//   float4 fLightAmbient;              // Offset:   32 Size:    16 [unused]
//   float4 fFlipbookParameter;         // Offset:   48 Size:    16
//   float4 fUVDistortionParameter;     // Offset:   64 Size:    16
//   float4 fBlendTextureParameter;     // Offset:   80 Size:    16
//   float4 fCameraFrontDirection;      // Offset:   96 Size:    16
//   
//   struct
//   {
//       
//       float4 Param;                  // Offset:  112
//       float4 BeginColor;             // Offset:  128
//       float4 EndColor;               // Offset:  144
//
//   } fFalloffParam;                   // Offset:  112 Size:    48
//   float4 fEmissiveScaling;           // Offset:  160 Size:    16
//   float4 fEdgeColor;                 // Offset:  176 Size:    16
//   float4 fEdgeParameter;             // Offset:  192 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_colorSampler                    sampler      NA          NA    0        1
// g_alphaSampler                    sampler      NA          NA    2        1
// g_uvDistortionSampler             sampler      NA          NA    3        1
// g_blendSampler                    sampler      NA          NA    4        1
// g_blendAlphaSampler               sampler      NA          NA    5        1
// g_blendUVDistortionSampler        sampler      NA          NA    6        1
// g_colorTexture                    texture  float4          2d    0        1
// g_alphaTexture                    texture  float4          2d    2        1
// g_uvDistortionTexture             texture  float4          2d    3        1
// g_blendTexture                    texture  float4          2d    4        1
// g_blendAlphaTexture               texture  float4          2d    5        1
// g_blendUVDistortionTexture        texture  float4          2d    6        1
// PS_ConstanBuffer                  cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// TEXCOORD                 0   xy          1     NONE  float   xy  
// TEXCOORD                 4     zw        1     NONE  float     zw
// TEXCOORD                 1   xyz         2     NONE  float   xyz 
// TEXCOORD                 9      w        2     NONE  float      w
// TEXCOORD                 2   xyz         3     NONE  float       
// TEXCOORD                 3   xyz         4     NONE  float       
// TEXCOORD                 5   xy          5     NONE  float   xy  
// TEXCOORD                 6     zw        5     NONE  float     zw
// TEXCOORD                 7   xy          6     NONE  float   xy  
// TEXCOORD                 8     zw        6     NONE  float     zw
// TEXCOORD                10   xy          7     NONE  float   xy  
// TEXCOORD                11     z         7     NONE  float     z 
// COLOR                    0   xyzw        8     NONE  float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
ps_4_0
dcl_constantbuffer cb0[13], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s2, mode_default
dcl_sampler s3, mode_default
dcl_sampler s4, mode_default
dcl_sampler s5, mode_default
dcl_sampler s6, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t2
dcl_resource_texture2d (float,float,float,float) t3
dcl_resource_texture2d (float,float,float,float) t4
dcl_resource_texture2d (float,float,float,float) t5
dcl_resource_texture2d (float,float,float,float) t6
dcl_input_ps linear v1.xy
dcl_input_ps linear v1.zw
dcl_input_ps linear v2.xyz
dcl_input_ps linear v2.w
dcl_input_ps linear v5.xy
dcl_input_ps linear v5.zw
dcl_input_ps linear v6.xy
dcl_input_ps linear v6.zw
dcl_input_ps linear v7.xy
dcl_input_ps linear v7.z
dcl_input_ps linear v8.xyzw
dcl_output o0.xyzw
dcl_temps 7
sample r0.xyzw, v5.xyxx, t3.xyzw, s3
mad r0.xy, r0.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mad r1.xyzw, r0.xyxy, cb0[4].xxxx, v1.xyzw
sample r2.xyzw, r1.xyxx, t0.xyzw, s0
mul r2.xyzw, r2.xyzw, v8.xyzw
lt r0.z, l(0.000000), cb0[3].x
if_nz r0.z
  mad r0.xy, r0.xyxx, cb0[4].xxxx, v7.xyxx
  sample r0.xyzw, r0.xyxx, t0.xyzw, s0
  eq r1.x, cb0[3].y, l(1.000000)
  mad r0.xyzw, r0.xyzw, v8.xyzw, -r2.xyzw
  mad r0.xyzw, v2.wwww, r0.xyzw, r2.xyzw
  movc r2.xyzw, r1.xxxx, r0.xyzw, r2.xyzw
endif 
sample r0.xyzw, r1.zwzz, t2.xyzw, s2
mul r0.x, r0.w, r0.x
mul r0.w, r0.x, r2.w
sample r1.xyzw, v6.zwzz, t6.xyzw, s6
mad r1.xy, r1.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mad r1.zw, r1.xxxy, cb0[4].yyyy, v5.zzzw
sample r3.xyzw, r1.zwzz, t4.xyzw, s4
mad r1.xy, r1.xyxx, cb0[4].yyyy, v6.xyxx
sample r1.xyzw, r1.xyxx, t5.xyzw, s5
mul r1.x, r1.w, r1.x
mul r1.y, r1.x, r3.w
mul r4.xyz, r3.xyzx, r1.yyyy
mad r1.x, -r3.w, r1.x, l(1.000000)
mad r1.xzw, r1.xxxx, r2.xxyz, r4.xxyz
mad r5.xyz, r1.yyyy, r3.xyzx, r2.xyzx
mad r3.xyz, -r1.yyyy, r3.xyzx, r2.xyzx
eq r6.xyzw, cb0[5].xxxx, l(0.000000, 1.000000, 2.000000, 3.000000)
mul r4.xyz, r2.xyzx, r4.xyzx
movc r2.xyz, r6.wwww, r4.xyzx, r2.xyzx
movc r2.xyz, r6.zzzz, r3.xyzx, r2.xyzx
movc r2.xyz, r6.yyyy, r5.xyzx, r2.xyzx
movc r0.xyz, r6.xxxx, r1.xzwx, r2.xyzx
dp3 r1.x, -cb0[6].xyzx, -cb0[6].xyzx
rsq r1.x, r1.x
mul r1.xyz, r1.xxxx, -cb0[6].xyzx
dp3 r1.w, v2.xyzx, v2.xyzx
rsq r1.w, r1.w
mul r2.xyz, r1.wwww, v2.xyzx
dp3_sat r1.x, r1.xyzx, r2.xyzx
log r1.x, r1.x
mul r1.x, r1.x, cb0[7].z
exp r1.x, r1.x
add r2.xyzw, cb0[8].xyzw, -cb0[9].xyzw
mad r1.xyzw, r1.xxxx, r2.xyzw, cb0[9].xyzw
add r2.xyz, r0.xyzx, r1.xyzx
add r3.xyz, r0.xyzx, -r1.xyzx
eq r4.xyzw, cb0[7].xyyy, l(1.000000, 0.000000, 1.000000, 2.000000)
mul r1.xyz, r0.xyzx, r1.xyzx
movc r1.xyz, r4.wwww, r1.xyzx, r0.xyzx
movc r1.xyz, r4.zzzz, r3.xyzx, r1.xyzx
movc r2.xyz, r4.yyyy, r2.xyzx, r1.xyzx
mul r2.w, r0.w, r1.w
movc r0.xyzw, r4.xxxx, r2.xyzw, r0.xyzw
ge r1.x, v7.z, r0.w
discard r1.x
eq r1.x, r0.w, l(0.000000)
discard r1.x
mul r1.xyz, cb0[11].xyzx, cb0[12].yyyy
add r1.w, r0.w, -v7.z
add r1.w, r1.w, -cb0[12].x
round_pi r1.w, r1.w
mad r0.xyz, r0.xyzx, cb0[10].xxxx, -r1.xyzx
mad o0.xyz, r1.wwww, r0.xyzx, r1.xyzx
mov o0.w, r0.w
ret 
// Approximately 69 instruction slots used
#endif

const BYTE g_PS[] =
{
     68,  88,  66,  67, 165,  78, 
    165, 207, 130, 192, 253,  94, 
     52, 129, 106, 202,   5,  73, 
     54, 147,   1,   0,   0,   0, 
    172,  17,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    108,   5,   0,   0, 232,   6, 
      0,   0,  28,   7,   0,   0, 
     48,  17,   0,   0,  82,  68, 
     69,  70,  48,   5,   0,   0, 
      1,   0,   0,   0, 180,   2, 
      0,   0,  13,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    255, 255,  16,   1,   0,   0, 
    255,   4,   0,   0, 188,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    203,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 218,   1,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 240,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    255,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  19,   2,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  46,   2, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
     61,   2,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   2,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0,  76,   2,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,  98,   2, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      4,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
    113,   2,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   5,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 133,   2,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   6,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0, 160,   2, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    103,  95,  99, 111, 108, 111, 
    114,  83,  97, 109, 112, 108, 
    101, 114,   0, 103,  95,  97, 
    108, 112, 104,  97,  83,  97, 
    109, 112, 108, 101, 114,   0, 
    103,  95, 117, 118,  68, 105, 
    115, 116, 111, 114, 116, 105, 
    111, 110,  83,  97, 109, 112, 
    108, 101, 114,   0, 103,  95, 
     98, 108, 101, 110, 100,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 103,  95,  98, 108, 101, 
    110, 100,  65, 108, 112, 104, 
     97,  83,  97, 109, 112, 108, 
    101, 114,   0, 103,  95,  98, 
    108, 101, 110, 100,  85,  86, 
     68, 105, 115, 116, 111, 114, 
    116, 105, 111, 110,  83,  97, 
    109, 112, 108, 101, 114,   0, 
    103,  95,  99, 111, 108, 111, 
    114,  84, 101, 120, 116, 117, 
    114, 101,   0, 103,  95,  97, 
    108, 112, 104,  97,  84, 101, 
    120, 116, 117, 114, 101,   0, 
    103,  95, 117, 118,  68, 105, 
    115, 116, 111, 114, 116, 105, 
    111, 110,  84, 101, 120, 116, 
    117, 114, 101,   0, 103,  95, 
     98, 108, 101, 110, 100,  84, 
    101, 120, 116, 117, 114, 101, 
      0, 103,  95,  98, 108, 101, 
    110, 100,  65, 108, 112, 104, 
     97,  84, 101, 120, 116, 117, 
    114, 101,   0, 103,  95,  98, 
    108, 101, 110, 100,  85,  86, 
     68, 105, 115, 116, 111, 114, 
    116, 105, 111, 110,  84, 101, 
    120, 116, 117, 114, 101,   0, 
     80,  83,  95,  67, 111, 110, 
    115, 116,  97, 110,  66, 117, 
    102, 102, 101, 114,   0, 171, 
    171, 171, 160,   2,   0,   0, 
     11,   0,   0,   0, 204,   2, 
      0,   0, 208,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 212,   3,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    228,   3,   0,   0,   0,   0, 
      0,   0, 244,   3,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    228,   3,   0,   0,   0,   0, 
      0,   0,   0,   4,   0,   0, 
     32,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    228,   3,   0,   0,   0,   0, 
      0,   0,  14,   4,   0,   0, 
     48,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    228,   3,   0,   0,   0,   0, 
      0,   0,  33,   4,   0,   0, 
     64,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    228,   3,   0,   0,   0,   0, 
      0,   0,  56,   4,   0,   0, 
     80,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    228,   3,   0,   0,   0,   0, 
      0,   0,  79,   4,   0,   0, 
     96,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    228,   3,   0,   0,   0,   0, 
      0,   0, 101,   4,   0,   0, 
    112,   0,   0,   0,  48,   0, 
      0,   0,   2,   0,   0,   0, 
    196,   4,   0,   0,   0,   0, 
      0,   0, 212,   4,   0,   0, 
    160,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    228,   3,   0,   0,   0,   0, 
      0,   0, 229,   4,   0,   0, 
    176,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    228,   3,   0,   0,   0,   0, 
      0,   0, 240,   4,   0,   0, 
    192,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    228,   3,   0,   0,   0,   0, 
      0,   0, 102,  76, 105, 103, 
    104, 116,  68, 105, 114, 101, 
     99, 116, 105, 111, 110,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 102,  76, 
    105, 103, 104, 116,  67, 111, 
    108, 111, 114,   0, 102,  76, 
    105, 103, 104, 116,  65, 109, 
     98, 105, 101, 110, 116,   0, 
    102,  70, 108, 105, 112,  98, 
    111, 111, 107,  80,  97, 114, 
     97, 109, 101, 116, 101, 114, 
      0, 102,  85,  86,  68, 105, 
    115, 116, 111, 114, 116, 105, 
    111, 110,  80,  97, 114,  97, 
    109, 101, 116, 101, 114,   0, 
    102,  66, 108, 101, 110, 100, 
     84, 101, 120, 116, 117, 114, 
    101,  80,  97, 114,  97, 109, 
    101, 116, 101, 114,   0, 102, 
     67,  97, 109, 101, 114,  97, 
     70, 114, 111, 110, 116,  68, 
    105, 114, 101,  99, 116, 105, 
    111, 110,   0, 102,  70,  97, 
    108, 108, 111, 102, 102,  80, 
     97, 114,  97, 109,   0,  80, 
     97, 114,  97, 109,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     66, 101, 103, 105, 110,  67, 
    111, 108, 111, 114,   0,  69, 
    110, 100,  67, 111, 108, 111, 
    114,   0, 115,   4,   0,   0, 
    124,   4,   0,   0,   0,   0, 
      0,   0, 140,   4,   0,   0, 
    124,   4,   0,   0,  16,   0, 
      0,   0, 151,   4,   0,   0, 
    124,   4,   0,   0,  32,   0, 
      0,   0,   5,   0,   0,   0, 
      1,   0,  12,   0,   0,   0, 
      3,   0, 160,   4,   0,   0, 
    102,  69, 109, 105, 115, 115, 
    105, 118, 101,  83,  99,  97, 
    108, 105, 110, 103,   0, 102, 
     69, 100, 103, 101,  67, 111, 
    108, 111, 114,   0, 102,  69, 
    100, 103, 101,  80,  97, 114, 
     97, 109, 101, 116, 101, 114, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     57,  46,  50,  57,  46,  57, 
     53,  50,  46,  51,  49,  49, 
     49,   0,  73,  83,  71,  78, 
    116,   1,   0,   0,  14,   0, 
      0,   0,   8,   0,   0,   0, 
     88,   1,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
    100,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   3,   3,   0,   0, 
    100,   1,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  12,  12,   0,   0, 
    100,   1,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   7,   7,   0,   0, 
    100,   1,   0,   0,   9,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   8,   8,   0,   0, 
    100,   1,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
    100,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   7,   0,   0,   0, 
    100,   1,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,   3,   3,   0,   0, 
    100,   1,   0,   0,   6,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,  12,  12,   0,   0, 
    100,   1,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   6,   0, 
      0,   0,   3,   3,   0,   0, 
    100,   1,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   6,   0, 
      0,   0,  12,  12,   0,   0, 
    100,   1,   0,   0,  10,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   7,   0, 
      0,   0,   3,   3,   0,   0, 
    100,   1,   0,   0,  11,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   7,   0, 
      0,   0,   4,   4,   0,   0, 
    109,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   8,   0, 
      0,   0,  15,  15,   0,   0, 
     83,  86,  95,  80,  79,  83, 
     73,  84,  73,  79,  78,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0,  67,  79,  76, 
     79,  82,   0, 171,  79,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  84, 
     97, 114, 103, 101, 116,   0, 
    171, 171,  83,  72,  68,  82, 
     12,  10,   0,   0,  64,   0, 
      0,   0, 131,   2,   0,   0, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     13,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      0,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      2,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      3,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      4,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      5,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      6,   0,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      0,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   2,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   3,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      4,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   5,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   6,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3, 194,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3, 114,  16,  16,   0, 
      2,   0,   0,   0,  98,  16, 
      0,   3, 130,  16,  16,   0, 
      2,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      5,   0,   0,   0,  98,  16, 
      0,   3, 194,  16,  16,   0, 
      5,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      6,   0,   0,   0,  98,  16, 
      0,   3, 194,  16,  16,   0, 
      6,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      7,   0,   0,   0,  98,  16, 
      0,   3,  66,  16,  16,   0, 
      7,   0,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      8,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   7,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  16,  16,   0,   5,   0, 
      0,   0,  70, 126,  16,   0, 
      3,   0,   0,   0,   0,  96, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  15,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   4,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70,  30,  16,   0,   8,   0, 
      0,   0,  49,   0,   0,   8, 
     66,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  31,   0, 
      4,   3,  42,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  10,  50,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     70,  16,  16,   0,   7,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  24,   0,   0,   8, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70,  30,  16,   0,   8,   0, 
      0,   0,  70,  14,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  50,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0, 246,  31,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  55,   0,   0,   9, 
    242,   0,  16,   0,   2,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  21,   0,   0,   1, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
    230,  10,  16,   0,   1,   0, 
      0,   0,  70, 126,  16,   0, 
      2,   0,   0,   0,   0,  96, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   1,   0, 
      0,   0, 230,  26,  16,   0, 
      6,   0,   0,   0,  70, 126, 
     16,   0,   6,   0,   0,   0, 
      0,  96,  16,   0,   6,   0, 
      0,   0,  50,   0,   0,  15, 
     50,   0,  16,   0,   1,   0, 
      0,   0,  70,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,  64, 
      0,   0,   0,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128, 191,   0,   0, 128, 191, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  50,   0,   0,  10, 
    194,   0,  16,   0,   1,   0, 
      0,   0,   6,   4,  16,   0, 
      1,   0,   0,   0,  86, 133, 
     32,   0,   0,   0,   0,   0, 
      4,   0,   0,   0, 166,  30, 
     16,   0,   5,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   3,   0,   0,   0, 
    230,  10,  16,   0,   1,   0, 
      0,   0,  70, 126,  16,   0, 
      4,   0,   0,   0,   0,  96, 
     16,   0,   4,   0,   0,   0, 
     50,   0,   0,  10,  50,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   1,   0, 
      0,   0,  86, 133,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  70,  16,  16,   0, 
      6,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 126,  16,   0,   5,   0, 
      0,   0,   0,  96,  16,   0, 
      5,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0,  86,   5,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10,  18,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  50,   0,   0,   9, 
    210,   0,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,   6,   9, 
     16,   0,   2,   0,   0,   0, 
      6,   9,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,   9, 
    114,   0,  16,   0,   5,   0, 
      0,   0,  86,   5,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,  10, 
    114,   0,  16,   0,   3,   0, 
      0,   0,  86,   5,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     24,   0,   0,  11, 242,   0, 
     16,   0,   6,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,  64,   0,   0, 
     64,  64,  56,   0,   0,   7, 
    114,   0,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   4,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   2,   0,   0,   0, 
    246,  15,  16,   0,   6,   0, 
      0,   0,  70,   2,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   2,   0,   0,   0, 
    166,  10,  16,   0,   6,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     86,   5,  16,   0,   6,   0, 
      0,   0,  70,   2,  16,   0, 
      5,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   6,   0, 
      0,   0, 134,   3,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     16,   0,   0,  11,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  32, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  68,   0,   0,   5, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0,   6,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  32, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,  16,   0, 
      0,   7, 130,   0,  16,   0, 
      1,   0,   0,   0,  70,  18, 
     16,   0,   2,   0,   0,   0, 
     70,  18,  16,   0,   2,   0, 
      0,   0,  68,   0,   0,   5, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      2,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     70,  18,  16,   0,   2,   0, 
      0,   0,  16,  32,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     47,   0,   0,   5,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   8, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,  25,   0, 
      0,   5,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,  10, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     70, 142,  32, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,   6,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,   0,   0,   0,   7, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   8, 114,   0, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70,   2,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  24,   0,   0,  11, 
    242,   0,  16,   0,   4,   0, 
      0,   0,  70, 133,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,  64,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0, 246,  15,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0, 166,  10,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  55,   0,   0,   9, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  86,   5,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   4,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     29,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     42,  16,  16,   0,   7,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  13,   0, 
      4,   3,  10,   0,  16,   0, 
      1,   0,   0,   0,  24,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  13,   0,   4,   3, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,  86, 133,  32,   0, 
      0,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   8, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  42,  16, 
     16, 128,  65,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   9, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     10, 128,  32, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     12,   0,   0,   0,  66,   0, 
      0,   5, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  11, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,  10,   0, 
      0,   0,  70,   2,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,   9, 
    114,  32,  16,   0,   0,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   5, 
    130,  32,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    116,   0,   0,   0,  69,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,  12,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      9,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};
