/* METH1.f -- translated by f2c (version 19970805).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#ifdef __cplusplus
extern "C" {
#endif
/* OTB patches: replace "f2c.h" by "otb_6S.h" */
/*#include "f2c.h"*/
#include "otb_6S.h"

/*<       subroutine    meth1(a,inu) >*/
/* Subroutine */ int meth1_(doublereal *a, integer *inu)
{
    /* Initialized data */

    static doublereal acr[2048]	/* was [8][256] */ = { 1.4454,.47807,.0052823,
	    -3.0056e-5,.002903,-2.686e-5,2500.,2510.,8.7736,.49348,3.8511e-4,
	    -6.0533e-6,1.0891e-4,-9.3895e-6,2510.,2520.,5.7188,.51082,
	    3.239e-4,-7.2399e-6,1.6424e-4,-1.0608e-5,2520.,2530.,4.5159,
	    .73333,5.5152e-4,-2.5526e-6,2.6319e-4,-1.1149e-5,2530.,2540.,
	    6.2089,.57459,-5.1671e-5,-3.2924e-6,-.0012056,-7.7167e-6,2540.,
	    2550.,9.8841,.5111,-.0015575,1.7182e-6,-.001203,-3.8007e-6,2550.,
	    2560.,7.6169,.80719,1.2985e-4,-5.7517e-6,-.0011789,-6.7688e-6,
	    2560.,2570.,7.3766,.91538,-6.9626e-4,-9.8403e-8,-.0010951,
	    -5.6422e-6,2570.,2580.,7.9669,1.0249,-.0020553,6.0631e-6,
	    -.0025043,1.2199e-6,2580.,2590.,12.942,1.8227,.0016813,-1.019e-5,
	    8.4177e-4,-1.3848e-5,2590.,2600.,11.671,.93909,-.0023388,
	    7.1737e-6,-.0030848,1.0079e-5,2600.,2610.,7.682,.22382,-.0036797,
	    1.7419e-5,-.002062,2.0955e-5,2610.,2620.,5.628,.56037,-.0012398,
	    1.026e-5,-.001454,8.1367e-6,2620.,2630.,14.127,1.2843,7.6229e-5,
	    5.7331e-6,-6.8637e-4,-4.6206e-6,2630.,2640.,9.0425,1.3886,
	    .0042412,2.3021e-6,.0040176,-2.0017e-5,2640.,2650.,10.155,.90252,
	    9.0385e-6,1.3215e-5,-4.9853e-4,-1.2678e-6,2650.,2660.,10.154,
	    .79137,.0031844,-3.2869e-6,.0011834,-1.1313e-5,2660.,2670.,11.725,
	    .70879,-.0014287,1.8146e-6,-.0025033,-1.0406e-7,2670.,2680.,
	    14.948,.92692,.0062395,-3.3167e-5,.0031727,-2.6064e-5,2680.,2690.,
	    26.279,.87829,.0028361,-1.4791e-5,.0014018,-1.4682e-5,2690.,2700.,
	    7.1745,.92595,.0030055,-2.7951e-6,.0045235,-2.2596e-5,2700.,2710.,
	    27.757,.81447,.0030565,-1.9569e-5,.0025866,-2.0025e-5,2710.,2720.,
	    36.518,.82512,.0018262,-1.5755e-5,.0012027,-1.7464e-5,2720.,2730.,
	    7.1564,.77634,.0051047,-2.7255e-5,.003528,-2.6912e-5,2730.,2740.,
	    53.441,.64417,-7.6181e-5,-1.012e-5,-8.2299e-4,-9.7201e-6,2740.,
	    2750.,38.926,.7434,-6.9195e-4,-4.3135e-6,2.1091e-4,-6.9939e-6,
	    2750.,2760.,15.709,1.3287,.0030102,-4.8796e-6,.0052525,-2.2331e-5,
	    2760.,2770.,54.733,1.246,-.0010987,5.2563e-6,.002214,-1.2844e-5,
	    2770.,2780.,47.55,1.5791,8.4509e-4,-2.0192e-6,.0011472,-1.6086e-5,
	    2780.,2790.,66.52,1.2817,-2.9084e-4,-6.0279e-6,-.0013817,
	    -7.9406e-6,2790.,2800.,54.178,.80208,-.0020375,1.3886e-6,-.002404,
	    9.4209e-6,2800.,2810.,53.2,.65974,-7.1708e-4,8.8569e-6,-2.5373e-4,
	    1.13e-5,2810.,2820.,148.4,.84587,-.0016143,2.0628e-6,-9.7561e-4,
	    9.6287e-6,2820.,2830.,45.29,1.3591,-2.3074e-4,1.8732e-5,.0020323,
	    6.678e-6,2830.,2840.,32.141,1.1794,7.5732e-4,5.0043e-5,.005454,
	    1.3952e-6,2840.,2850.,52.919,.85346,.0010685,4.9698e-5,.0029632,
	    1.729e-5,2850.,2860.,92.855,1.2724,.0034021,3.1892e-5,.0020937,
	    7.5591e-6,2860.,2870.,115.15,1.6724,.0068873,1.0637e-5,.0045477,
	    -1.5654e-5,2870.,2880.,149.81,1.2641,.0081325,-1.1177e-6,.0053865,
	    -1.8572e-5,2880.,2890.,225.46,.83931,.011197,-4.4342e-5,.0080886,
	    -3.4016e-5,2890.,2900.,337.19,.68846,.0074267,-2.7002e-5,.0051288,
	    -1.7032e-5,2900.,2910.,593.38,.59397,.0062712,-3.0983e-5,.0039217,
	    -1.5025e-5,2910.,2920.,814.37,.44567,.0050972,-3.2548e-5,.0037255,
	    -1.8409e-5,2920.,2930.,1008.,.42373,.002722,-2.2438e-5,.001776,
	    -8.5011e-6,2930.,2940.,1273.8,.39048,9.1833e-4,-1.5902e-5,
	    3.8752e-4,-6.11e-6,2940.,2950.,1822.6,.32354,-8.3613e-4,
	    -9.1286e-6,-.0012748,6.4576e-7,2950.,2960.,1144.9,.28404,
	    -.0022237,-3.1413e-6,-.0015533,4e-6,2960.,2970.,1422.2,.24694,
	    -.0034946,2.0028e-6,-.0022609,9.6681e-6,2970.,2980.,1129.9,.25225,
	    -.0043236,6.0179e-6,-.0023072,8.9383e-6,2980.,2990.,382.43,.28365,
	    -.0047369,1.1124e-5,.0018248,1.9257e-5,2990.,3e3,231.12,2.8616,
	    .0085402,4.3691e-5,.016112,-4.2673e-5,3e3,3010.,12795.,1.9671,
	    -2.1206e-4,-1.4984e-6,-3.9307e-4,-5.8544e-6,3010.,3020.,578.69,
	    .79629,-.0043645,1.3898e-5,7.3408e-4,-4.5626e-6,3020.,3030.,
	    434.57,.096576,-.0055811,1.294e-5,.0011172,2.1736e-5,3030.,3040.,
	    899.49,.11536,-.0052201,1.0059e-5,-.0015874,2.2277e-5,3040.,3050.,
	    2131.4,.12202,-.0045842,6.3207e-6,-.003267,2.194e-5,3050.,3060.,
	    2451.4,.19437,-.0035989,2.0635e-6,-.0037611,1.5519e-5,3060.,3070.,
	    1860.9,.31324,-.0022827,-2.6816e-6,-.0014644,8.4665e-6,3070.,
	    3080.,2857.1,.3194,-8.3645e-4,-9.0192e-6,-7.6302e-4,2.417e-6,
	    3080.,3090.,1935.6,.28235,9.2008e-4,-1.5863e-5,.0010109,
	    -1.3517e-6,3090.,3100.,1498.4,.32994,.0028983,-2.3966e-5,.0020895,
	    -9.8936e-6,3100.,3110.,1250.8,.36564,.005137,-3.2908e-5,.0037408,
	    -1.8191e-5,3110.,3120.,818.19,.45356,.0075913,-4.2727e-5,.0055871,
	    -2.645e-5,3120.,3130.,483.02,.62289,.010573,-5.4032e-5,.0075195,
	    -3.888e-5,3130.,3140.,405.16,1.0372,.01439,-6.8744e-5,.011121,
	    -5.8648e-5,3140.,3150.,80.532,.8961,.01798,-6.9816e-5,.012298,
	    -5.1675e-5,3150.,3160.,41.171,.85486,.021624,-8.2706e-5,.015717,
	    -6.4082e-5,3160.,3170.,18.087,.82972,.024369,-8.2555e-5,.018128,
	    -6.8246e-5,3170.,3180.,7.8303,.7783,.024083,-4.5258e-5,.018125,
	    -5.3074e-5,3180.,3190.,5.5218,1.2503,.023406,-1.2671e-6,.019648,
	    -4.075e-5,3190.,3200.,.69216,.51644,.01424,-8.731e-6,.01086,
	    -3.2732e-5,3200.,3210.,.30939,.2177,.0082095,-4.4565e-5,.0058697,
	    -4.1343e-5,3210.,3220.,.22568,.37985,.012091,-6.0525e-5,.0090838,
	    -5.5067e-5,3220.,3230.,.18766,.2799,.01283,-6.1005e-5,.010043,
	    -5.7718e-5,3230.,3240.,.063205,.18476,.014107,-6.7485e-5,.011333,
	    -6.3191e-5,3240.,3250.,.028821,.059172,.014986,-7.1903e-5,.012123,
	    -6.7129e-5,3250.,3260.,0.,0.,0.,0.,0.,0.,3260.,3270.,0.,0.,0.,0.,
	    0.,0.,3270.,3280.,0.,0.,0.,0.,0.,0.,3280.,3290.,0.,0.,0.,0.,0.,0.,
	    3290.,3300.,0.,0.,0.,0.,0.,0.,3300.,3310.,0.,0.,0.,0.,0.,0.,3310.,
	    3320.,0.,0.,0.,0.,0.,0.,3320.,3330.,0.,0.,0.,0.,0.,0.,3330.,3340.,
	    0.,0.,0.,0.,0.,0.,3340.,3350.,0.,0.,0.,0.,0.,0.,3350.,3360.,0.,0.,
	    0.,0.,0.,0.,3360.,3370.,0.,0.,0.,0.,0.,0.,3370.,3380.,0.,0.,0.,0.,
	    0.,0.,3380.,3390.,0.,0.,0.,0.,0.,0.,3390.,3400.,0.,0.,0.,0.,0.,0.,
	    3400.,3410.,0.,0.,0.,0.,0.,0.,3410.,3420.,0.,0.,0.,0.,0.,0.,3420.,
	    3430.,0.,0.,0.,0.,0.,0.,3430.,3440.,0.,0.,0.,0.,0.,0.,3440.,3450.,
	    0.,0.,0.,0.,0.,0.,3450.,3460.,0.,0.,0.,0.,0.,0.,3460.,3470.,0.,0.,
	    0.,0.,0.,0.,3470.,3480.,0.,0.,0.,0.,0.,0.,3480.,3490.,0.,0.,0.,0.,
	    0.,0.,3490.,3500.,0.,0.,0.,0.,0.,0.,3500.,3510.,0.,0.,0.,0.,0.,0.,
	    3510.,3520.,0.,0.,0.,0.,0.,0.,3520.,3530.,0.,0.,0.,0.,0.,0.,3530.,
	    3540.,0.,0.,0.,0.,0.,0.,3540.,3550.,0.,0.,0.,0.,0.,0.,3550.,3560.,
	    0.,0.,0.,0.,0.,0.,3560.,3570.,0.,0.,0.,0.,0.,0.,3570.,3580.,0.,0.,
	    0.,0.,0.,0.,3580.,3590.,0.,0.,0.,0.,0.,0.,3590.,3600.,0.,0.,0.,0.,
	    0.,0.,3600.,3610.,0.,0.,0.,0.,0.,0.,3610.,3620.,0.,0.,0.,0.,0.,0.,
	    3620.,3630.,0.,0.,0.,0.,0.,0.,3630.,3640.,0.,0.,0.,0.,0.,0.,3640.,
	    3650.,0.,0.,0.,0.,0.,0.,3650.,3660.,0.,0.,0.,0.,0.,0.,3660.,3670.,
	    0.,0.,0.,0.,0.,0.,3670.,3680.,0.,0.,0.,0.,0.,0.,3680.,3690.,0.,0.,
	    0.,0.,0.,0.,3690.,3700.,.014928,.049339,.0010215,-1.7301e-5,
	    -.0020195,-1.1177e-5,3700.,3710.,.086139,.13757,.0010215,
	    -1.7301e-5,-.0020195,-1.1177e-5,3710.,3720.,.067083,.12495,
	    .0010215,-1.7301e-5,-.0020195,-1.1177e-5,3720.,3730.,.020862,
	    .049275,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,3730.,3740.,
	    .067784,.11899,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,3740.,
	    3750.,.15027,.18565,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,
	    3750.,3760.,.31581,.26221,.0010215,-1.7301e-5,-.0020195,
	    -1.1177e-5,3760.,3770.,.48086,.2992,.0010215,-1.7301e-5,-.0020195,
	    -1.1177e-5,3770.,3780.,.59376,.29431,.0010215,-1.7301e-5,
	    -.0020195,-1.1177e-5,3780.,3790.,1.8375,.36994,.0010215,
	    -1.7301e-5,-.0020195,-1.1177e-5,3790.,3800.,2.5355,.40322,
	    .0010215,-1.7301e-5,-.0020195,-1.1177e-5,3800.,3810.,2.7002,
	    .43597,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,3810.,3820.,
	    6.1651,.55369,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,3820.,
	    3830.,4.0461,.57732,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,
	    3830.,3840.,6.3365,.67727,.0010215,-1.7301e-5,-.0020195,
	    -1.1177e-5,3840.,3850.,9.3866,.95498,.0010215,-1.7301e-5,
	    -.0020195,-1.1177e-5,3850.,3860.,20.329,1.0079,.0010215,
	    -1.7301e-5,-.0020195,-1.1177e-5,3860.,3870.,3.8488,.60704,
	    -.0030055,4.6922e-6,-.0036436,-2.5739e-6,3870.,3880.,11.688,
	    .69118,-.0033148,3.0917e-6,-.0045244,8.2466e-7,3880.,3890.,15.787,
	    .75496,-3.761e-4,-9.5219e-6,-.0028616,-7.036e-6,3890.,3900.,
	    12.339,1.2573,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,3900.,
	    3910.,4.4035,1.1712,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,
	    3910.,3920.,1.452,1.1029,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,
	    3920.,3930.,.94805,.51649,.0010215,-1.7301e-5,-.0020195,
	    -1.1177e-5,3930.,3940.,1.3512,.57924,.0010215,-1.7301e-5,
	    -.0020195,-1.1177e-5,3940.,3950.,1.2982,.5633,.0010215,-1.7301e-5,
	    -.0020195,-1.1177e-5,3950.,3960.,1.1898,.7034,.0010215,-1.7301e-5,
	    -.0020195,-1.1177e-5,3960.,3970.,1.2669,.70992,.0010215,
	    -1.7301e-5,-.0020195,-1.1177e-5,3970.,3980.,1.1486,.75703,
	    .0010215,-1.7301e-5,-.0020195,-1.1177e-5,3980.,3990.,.94294,
	    .67691,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,3990.,4e3,1.1722,
	    .71803,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,4e3,4010.,1.6614,
	    1.1434,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,4010.,4020.,
	    1.3169,.99418,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,4020.,
	    4030.,1.6675,1.5586,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,
	    4030.,4040.,2.2754,1.5263,.0010215,-1.7301e-5,-.0020195,
	    -1.1177e-5,4040.,4050.,3.3696,1.614,.0010215,-1.7301e-5,-.0020195,
	    -1.1177e-5,4050.,4060.,4.4078,1.7299,.0010215,-1.7301e-5,
	    -.0020195,-1.1177e-5,4060.,4070.,6.4093,1.6235,.0010215,
	    -1.7301e-5,-.0020195,-1.1177e-5,4070.,4080.,8.8553,1.445,.0010215,
	    -1.7301e-5,-.0020195,-1.1177e-5,4080.,4090.,8.5641,1.5633,
	    .0010215,-1.7301e-5,-.0020195,-1.1177e-5,4090.,4100.,16.356,
	    1.9485,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,4100.,4110.,
	    15.552,1.5099,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,4110.,
	    4120.,23.823,2.7996,.0010215,-1.7301e-5,-.0020195,-1.1177e-5,
	    4120.,4130.,18.843,1.4075,.0058105,-2.6748e-5,6.4011e-4,
	    -1.7934e-5,4130.,4140.,7.1651,.45187,.0070593,-2.9644e-5,.0039603,
	    -2.9724e-5,4140.,4150.,37.171,.44157,.0068418,-3.8862e-5,.0036076,
	    -3.2195e-5,4150.,4160.,38.158,.32296,.0043474,-2.9319e-5,.00185,
	    -2.5238e-5,4160.,4170.,65.621,.45796,.0022774,-2.0417e-5,8.223e-5,
	    -1.7919e-5,4170.,4180.,79.347,.33603,-8.4769e-4,-8.4263e-6,
	    -.0034772,-3.6512e-6,4180.,4190.,65.038,.4819,-.0014827,
	    -1.4444e-6,-.0022137,-5.6866e-6,4190.,4200.,86.982,.77363,
	    -7.1575e-4,2.9104e-7,-.0017062,-5.7132e-6,4200.,4210.,309.82,
	    1.6801,-8.9037e-4,-1.3593e-6,-.0021551,-4.6701e-6,4210.,4220.,
	    81.077,.588,-.0012356,-7.661e-7,-.0026793,-4.4252e-6,4220.,4230.,
	    89.975,.39899,-.0039748,5.6557e-6,-.0048805,4.5246e-6,4230.,4240.,
	    148.96,.80968,-.002216,-1.5823e-6,-.0039631,-2.9253e-7,4240.,
	    4250.,155.94,1.2514,4.5507e-4,-8.2566e-6,-.0014417,-8.5226e-6,
	    4250.,4260.,100.6,1.2829,.0020903,-1.6069e-5,-3.6824e-4,
	    -1.5144e-5,4260.,4270.,117.04,1.5739,5.5952e-4,-2.1104e-6,
	    -8.6496e-4,-9.3941e-6,4270.,4280.,72.794,1.549,-6.9688e-4,
	    -3.1516e-6,-.0027541,-2.9267e-6,4280.,4290.,55.269,.72223,
	    -.0034302,5.1174e-6,-.0052484,7.0355e-6,4290.,4300.,59.856,1.1762,
	    -5.5565e-4,2.0772e-7,-.0019773,-5.0966e-6,4300.,4310.,218.17,
	    2.2377,-.0013492,-1.8427e-6,-.0029966,-3.2329e-6,4310.,4320.,
	    10.284,.071846,-.0057696,9.8901e-6,-.0087876,1.5909e-5,4320.,
	    4330.,96.725,.88048,-.0045462,6.1508e-6,-.0069991,9.6787e-6,4330.,
	    4340.,111.26,1.6893,-.002444,5.0136e-7,-.0044752,1.1244e-6,4340.,
	    4350.,102.83,1.8062,-3.868e-4,-5.0005e-6,-.0021043,-6.8556e-6,
	    4350.,4360.,89.61,1.1851,-6.654e-4,2.3556e-6,-.001897,-3.4232e-6,
	    4360.,4370.,66.668,.73012,-.0022103,2.3323e-6,-.0030787,
	    -5.6056e-7,4370.,4380.,81.907,.54144,-.0025213,-8.9597e-7,
	    -.0047474,1.5149e-6,4380.,4390.,90.229,.49784,-.0023921,
	    -1.0143e-6,-.0043793,4.6547e-7,4390.,4400.,82.849,.85204,
	    -1.0412e-4,-8.1641e-6,-.0020032,-8.0151e-6,4400.,4410.,44.643,
	    .57527,.0023103,-1.4133e-5,8.589e-4,-1.8551e-5,4410.,4420.,69.032,
	    .78506,3.9855e-4,-1.0098e-5,-.0010159,-1.0449e-5,4420.,4430.,
	    58.683,.96123,.0024151,-1.8621e-5,9.2225e-4,-1.9737e-5,4430.,
	    4440.,37.181,1.0126,.0046217,-2.9919e-5,.0020589,-2.6447e-5,4440.,
	    4450.,42.607,1.0332,.0047981,-3.088e-5,.0014909,-2.4304e-5,4450.,
	    4460.,33.113,.94984,.0043677,-2.6166e-5,.0012754,-2.2104e-5,4460.,
	    4470.,32.668,.8529,.0023495,-1.622e-5,-4.7342e-4,-1.3768e-5,4470.,
	    4480.,23.216,.8354,.0022982,-7.3604e-6,6.8926e-4,-1.3485e-5,4480.,
	    4490.,13.719,.6592,.0014982,-6.2753e-6,-3.7161e-4,-1.1492e-5,
	    4490.,4500.,16.799,.41229,-7.848e-4,1.7545e-6,-.001216,-7.1041e-6,
	    4500.,4510.,10.085,.14021,-.0037976,6.6108e-6,-.0050669,6.8711e-6,
	    4510.,4520.,3.1009,.087599,-.0043682,1.0148e-5,-.0057555,
	    1.0223e-5,4520.,4530.,18.983,1.5932,.0014519,-9.1544e-6,
	    -9.7256e-4,-1.0139e-5,4530.,4540.,63.83,2.0016,-.0011189,
	    -2.1104e-6,-.0028048,-3.8802e-6,4540.,4550.,3.1441,.067773,
	    -.0040447,1.4471e-5,-.0037016,5.8757e-6,4550.,4560.,2.1782,
	    .029389,-.005929,1.0501e-5,-.00897,1.6625e-5,4560.,4570.,4.0086,
	    .078646,-.0053825,8.3305e-6,-.0083558,1.4185e-5,4570.,4580.,
	    1.3954,.11032,-.0040678,3.1725e-6,-.0071674,9.4743e-6,4580.,4590.,
	    8.2827,.13524,-.0044855,4.8983e-6,-.0072447,9.9023e-6,4590.,4600.,
	    8.1728,.18866,-.0033132,4.1656e-7,-.0059898,5.0092e-6,4600.,4610.,
	    6.4947,.31086,-.0016438,-5.9966e-6,-.0043498,-1.4967e-6,4610.,
	    4620.,6.3479,.34741,1.5663e-4,-1.2499e-5,-.0026034,-7.9833e-6,
	    4620.,4630.,2.4602,.20366,.0017162,-1.8956e-5,-9.66e-4,-1.4741e-5,
	    4630.,4640.,2.0994,.2061,.004364,-2.6098e-5,.0019605,-2.4954e-5,
	    4640.,4650.,1.6635,.21606,.0038987,-2.7059e-5,.001059,-2.2496e-5,
	    4650.,4660.,.9148,.11908,.0055341,-3.5022e-5,.002491,-2.9056e-5,
	    4660.,4670.,0.,0.,0.,0.,0.,0.,4670.,4680.,0.,0.,0.,0.,0.,0.,4680.,
	    4690.,0.,0.,0.,0.,0.,0.,4690.,4700.,0.,0.,0.,0.,0.,0.,4700.,4710.,
	    0.,0.,0.,0.,0.,0.,4710.,4720.,0.,0.,0.,0.,0.,0.,4720.,4730.,0.,0.,
	    0.,0.,0.,0.,4730.,4740.,0.,0.,0.,0.,0.,0.,4740.,4750.,0.,0.,0.,0.,
	    0.,0.,4750.,4760.,0.,0.,0.,0.,0.,0.,4760.,4770.,0.,0.,0.,0.,0.,0.,
	    4770.,4780.,0.,0.,0.,0.,0.,0.,4780.,4790.,0.,0.,0.,0.,0.,0.,4790.,
	    4800.,0.,0.,0.,0.,0.,0.,4800.,4810.,0.,0.,0.,0.,0.,0.,4810.,4820.,
	    0.,0.,0.,0.,0.,0.,4820.,4830.,0.,0.,0.,0.,0.,0.,4830.,4840.,0.,0.,
	    0.,0.,0.,0.,4840.,4850.,0.,0.,0.,0.,0.,0.,4850.,4860.,0.,0.,0.,0.,
	    0.,0.,4860.,4870.,0.,0.,0.,0.,0.,0.,4870.,4880.,0.,0.,0.,0.,0.,0.,
	    4880.,4890.,0.,0.,0.,0.,0.,0.,4890.,4900.,0.,0.,0.,0.,0.,0.,4900.,
	    4910.,0.,0.,0.,0.,0.,0.,4910.,4920.,0.,0.,0.,0.,0.,0.,4920.,4930.,
	    0.,0.,0.,0.,0.,0.,4930.,4940.,0.,0.,0.,0.,0.,0.,4940.,4950.,0.,0.,
	    0.,0.,0.,0.,4950.,4960.,0.,0.,0.,0.,0.,0.,4960.,4970.,0.,0.,0.,0.,
	    0.,0.,4970.,4980.,0.,0.,0.,0.,0.,0.,4980.,4990.,0.,0.,0.,0.,0.,0.,
	    4990.,5e3,0.,0.,0.,0.,0.,0.,5e3,5010.,0.,0.,0.,0.,0.,0.,5010.,
	    5020.,0.,0.,0.,0.,0.,0.,5020.,5030.,0.,0.,0.,0.,0.,0.,5030.,5040.,
	    0.,0.,0.,0.,0.,0.,5040.,5050.,0.,0.,0.,0.,0.,0.,5050.,5060. };

    integer i__;

/*<        real a(8) >*/
/*<        real acr(8,256) >*/
/*<        integer inu,j,k,i >*/
/*     methane (2500 - 5050 cm-1) */

/*<    >*/
    /* Parameter adjustments */
    --a;

    /* Function Body */
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/
/*<    >*/

/*<       do i=1,8 >*/
    for (i__ = 1; i__ <= 8; ++i__) {
/*<       a(i)=acr(i,inu) >*/
	a[i__] = acr[i__ + (*inu << 3) - 9];
/*<       enddo >*/
    }

/*<       return >*/
    return 0;
/*<       end >*/
} /* meth1_ */

#ifdef __cplusplus
	}
#endif