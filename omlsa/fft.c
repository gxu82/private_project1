/*
 * File: fft.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 09-Nov-2018 14:14:28
 */

/* Include Files */
 
#include "fft.h"

/* Function Definitions */

/*
 * Arguments    : const double x[512]
 *                creal_T y[512]
 * Return Type  : void
 */
void fft(const double x[512], creal_T y[512])
{
  int ix;
  int ju;
  int iy;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int iheight;
  int istart;
  int j;
  double twid_re;
  static const double dv1[257] = { 1.0, 0.9999247018391445, 0.99969881869620425,
    0.99932238458834954, 0.99879545620517241, 0.99811811290014918,
    0.99729045667869021, 0.996312612182778, 0.99518472667219693,
    0.99390697000235606, 0.99247953459871, 0.99090263542778, 0.989176509964781,
    0.98730141815785843, 0.98527764238894122, 0.98310548743121629,
    0.98078528040323043, 0.97831737071962765, 0.97570213003852857,
    0.97293995220556018, 0.970031253194544, 0.96697647104485207,
    0.96377606579543984, 0.96043051941556579, 0.95694033573220882,
    0.95330604035419386, 0.94952818059303667, 0.94560732538052128,
    0.94154406518302081, 0.937339011912575, 0.932992798834739,
    0.92850608047321559, 0.92387953251128674, 0.91911385169005777,
    0.91420975570353069, 0.90916798309052238, 0.90398929312344334,
    0.89867446569395382, 0.89322430119551532, 0.88763962040285393,
    0.881921264348355, 0.8760700941954066, 0.87008699110871146,
    0.8639728561215867, 0.85772861000027212, 0.8513551931052652,
    0.84485356524970712, 0.83822470555483808, 0.83146961230254524,
    0.82458930278502529, 0.81758481315158371, 0.81045719825259477,
    0.80320753148064494, 0.79583690460888357, 0.78834642762660634,
    0.78073722857209449, 0.773010453362737, 0.765167265622459,
    0.75720884650648457, 0.74913639452345937, 0.74095112535495922,
    0.73265427167241282, 0.724247082951467, 0.71573082528381859,
    0.70710678118654757, 0.69837624940897292, 0.68954054473706683,
    0.680600997795453, 0.67155895484701833, 0.66241577759017178,
    0.65317284295377676, 0.64383154288979139, 0.63439328416364549,
    0.62485948814238634, 0.61523159058062682, 0.60551104140432555,
    0.59569930449243336, 0.58579785745643886, 0.57580819141784534,
    0.56573181078361312, 0.55557023301960218, 0.54532498842204646,
    0.53499761988709715, 0.524589682678469, 0.51410274419322166,
    0.50353838372571758, 0.49289819222978404, 0.48218377207912272,
    0.47139673682599764, 0.46053871095824, 0.44961132965460654,
    0.43861623853852766, 0.42755509343028208, 0.41642956009763715,
    0.40524131400498986, 0.3939920400610481, 0.38268343236508978,
    0.37131719395183749, 0.35989503653498811, 0.34841868024943456,
    0.33688985339222005, 0.32531029216226293, 0.31368174039889152,
    0.30200594931922808, 0.29028467725446233, 0.27851968938505306,
    0.26671275747489837, 0.25486565960451457, 0.24298017990326387,
    0.23105810828067111, 0.2191012401568698, 0.20711137619221856,
    0.19509032201612825, 0.18303988795514095, 0.17096188876030122,
    0.15885814333386145, 0.14673047445536175, 0.13458070850712617,
    0.1224106751992162, 0.11022220729388306, 0.0980171403295606,
    0.0857973123444399, 0.073564563599667426, 0.061320736302208578,
    0.049067674327418015, 0.036807222941358832, 0.024541228522912288,
    0.012271538285719925, 0.0, -0.012271538285719925, -0.024541228522912288,
    -0.036807222941358832, -0.049067674327418015, -0.061320736302208578,
    -0.073564563599667426, -0.0857973123444399, -0.0980171403295606,
    -0.11022220729388306, -0.1224106751992162, -0.13458070850712617,
    -0.14673047445536175, -0.15885814333386145, -0.17096188876030122,
    -0.18303988795514095, -0.19509032201612825, -0.20711137619221856,
    -0.2191012401568698, -0.23105810828067111, -0.24298017990326387,
    -0.25486565960451457, -0.26671275747489837, -0.27851968938505306,
    -0.29028467725446233, -0.30200594931922808, -0.31368174039889152,
    -0.32531029216226293, -0.33688985339222005, -0.34841868024943456,
    -0.35989503653498811, -0.37131719395183749, -0.38268343236508978,
    -0.3939920400610481, -0.40524131400498986, -0.41642956009763715,
    -0.42755509343028208, -0.43861623853852766, -0.44961132965460654,
    -0.46053871095824, -0.47139673682599764, -0.48218377207912272,
    -0.49289819222978404, -0.50353838372571758, -0.51410274419322166,
    -0.524589682678469, -0.53499761988709715, -0.54532498842204646,
    -0.55557023301960218, -0.56573181078361312, -0.57580819141784534,
    -0.58579785745643886, -0.59569930449243336, -0.60551104140432555,
    -0.61523159058062682, -0.62485948814238634, -0.63439328416364549,
    -0.64383154288979139, -0.65317284295377676, -0.66241577759017178,
    -0.67155895484701833, -0.680600997795453, -0.68954054473706683,
    -0.69837624940897292, -0.70710678118654757, -0.71573082528381859,
    -0.724247082951467, -0.73265427167241282, -0.74095112535495922,
    -0.74913639452345937, -0.75720884650648457, -0.765167265622459,
    -0.773010453362737, -0.78073722857209449, -0.78834642762660634,
    -0.79583690460888357, -0.80320753148064494, -0.81045719825259477,
    -0.81758481315158371, -0.82458930278502529, -0.83146961230254524,
    -0.83822470555483808, -0.84485356524970712, -0.8513551931052652,
    -0.85772861000027212, -0.8639728561215867, -0.87008699110871146,
    -0.8760700941954066, -0.881921264348355, -0.88763962040285393,
    -0.89322430119551532, -0.89867446569395382, -0.90398929312344334,
    -0.90916798309052238, -0.91420975570353069, -0.91911385169005777,
    -0.92387953251128674, -0.92850608047321559, -0.932992798834739,
    -0.937339011912575, -0.94154406518302081, -0.94560732538052128,
    -0.94952818059303667, -0.95330604035419386, -0.95694033573220882,
    -0.96043051941556579, -0.96377606579543984, -0.96697647104485207,
    -0.970031253194544, -0.97293995220556018, -0.97570213003852857,
    -0.97831737071962765, -0.98078528040323043, -0.98310548743121629,
    -0.98527764238894122, -0.98730141815785843, -0.989176509964781,
    -0.99090263542778, -0.99247953459871, -0.99390697000235606,
    -0.99518472667219693, -0.996312612182778, -0.99729045667869021,
    -0.99811811290014918, -0.99879545620517241, -0.99932238458834954,
    -0.99969881869620425, -0.9999247018391445, -1.0 };

  double twid_im;
  static const double dv2[257] = { 0.0, -0.012271538285719925,
    -0.024541228522912288, -0.036807222941358832, -0.049067674327418015,
    -0.061320736302208578, -0.073564563599667426, -0.0857973123444399,
    -0.0980171403295606, -0.11022220729388306, -0.1224106751992162,
    -0.13458070850712617, -0.14673047445536175, -0.15885814333386145,
    -0.17096188876030122, -0.18303988795514095, -0.19509032201612825,
    -0.20711137619221856, -0.2191012401568698, -0.23105810828067111,
    -0.24298017990326387, -0.25486565960451457, -0.26671275747489837,
    -0.27851968938505306, -0.29028467725446233, -0.30200594931922808,
    -0.31368174039889152, -0.32531029216226293, -0.33688985339222005,
    -0.34841868024943456, -0.35989503653498811, -0.37131719395183749,
    -0.38268343236508978, -0.3939920400610481, -0.40524131400498986,
    -0.41642956009763715, -0.42755509343028208, -0.43861623853852766,
    -0.44961132965460654, -0.46053871095824, -0.47139673682599764,
    -0.48218377207912272, -0.49289819222978404, -0.50353838372571758,
    -0.51410274419322166, -0.524589682678469, -0.53499761988709715,
    -0.54532498842204646, -0.55557023301960218, -0.56573181078361312,
    -0.57580819141784534, -0.58579785745643886, -0.59569930449243336,
    -0.60551104140432555, -0.61523159058062682, -0.62485948814238634,
    -0.63439328416364549, -0.64383154288979139, -0.65317284295377676,
    -0.66241577759017178, -0.67155895484701833, -0.680600997795453,
    -0.68954054473706683, -0.69837624940897292, -0.70710678118654757,
    -0.71573082528381859, -0.724247082951467, -0.73265427167241282,
    -0.74095112535495922, -0.74913639452345937, -0.75720884650648457,
    -0.765167265622459, -0.773010453362737, -0.78073722857209449,
    -0.78834642762660634, -0.79583690460888357, -0.80320753148064494,
    -0.81045719825259477, -0.81758481315158371, -0.82458930278502529,
    -0.83146961230254524, -0.83822470555483808, -0.84485356524970712,
    -0.8513551931052652, -0.85772861000027212, -0.8639728561215867,
    -0.87008699110871146, -0.8760700941954066, -0.881921264348355,
    -0.88763962040285393, -0.89322430119551532, -0.89867446569395382,
    -0.90398929312344334, -0.90916798309052238, -0.91420975570353069,
    -0.91911385169005777, -0.92387953251128674, -0.92850608047321559,
    -0.932992798834739, -0.937339011912575, -0.94154406518302081,
    -0.94560732538052128, -0.94952818059303667, -0.95330604035419386,
    -0.95694033573220882, -0.96043051941556579, -0.96377606579543984,
    -0.96697647104485207, -0.970031253194544, -0.97293995220556018,
    -0.97570213003852857, -0.97831737071962765, -0.98078528040323043,
    -0.98310548743121629, -0.98527764238894122, -0.98730141815785843,
    -0.989176509964781, -0.99090263542778, -0.99247953459871,
    -0.99390697000235606, -0.99518472667219693, -0.996312612182778,
    -0.99729045667869021, -0.99811811290014918, -0.99879545620517241,
    -0.99932238458834954, -0.99969881869620425, -0.9999247018391445, -1.0,
    -0.9999247018391445, -0.99969881869620425, -0.99932238458834954,
    -0.99879545620517241, -0.99811811290014918, -0.99729045667869021,
    -0.996312612182778, -0.99518472667219693, -0.99390697000235606,
    -0.99247953459871, -0.99090263542778, -0.989176509964781,
    -0.98730141815785843, -0.98527764238894122, -0.98310548743121629,
    -0.98078528040323043, -0.97831737071962765, -0.97570213003852857,
    -0.97293995220556018, -0.970031253194544, -0.96697647104485207,
    -0.96377606579543984, -0.96043051941556579, -0.95694033573220882,
    -0.95330604035419386, -0.94952818059303667, -0.94560732538052128,
    -0.94154406518302081, -0.937339011912575, -0.932992798834739,
    -0.92850608047321559, -0.92387953251128674, -0.91911385169005777,
    -0.91420975570353069, -0.90916798309052238, -0.90398929312344334,
    -0.89867446569395382, -0.89322430119551532, -0.88763962040285393,
    -0.881921264348355, -0.8760700941954066, -0.87008699110871146,
    -0.8639728561215867, -0.85772861000027212, -0.8513551931052652,
    -0.84485356524970712, -0.83822470555483808, -0.83146961230254524,
    -0.82458930278502529, -0.81758481315158371, -0.81045719825259477,
    -0.80320753148064494, -0.79583690460888357, -0.78834642762660634,
    -0.78073722857209449, -0.773010453362737, -0.765167265622459,
    -0.75720884650648457, -0.74913639452345937, -0.74095112535495922,
    -0.73265427167241282, -0.724247082951467, -0.71573082528381859,
    -0.70710678118654757, -0.69837624940897292, -0.68954054473706683,
    -0.680600997795453, -0.67155895484701833, -0.66241577759017178,
    -0.65317284295377676, -0.64383154288979139, -0.63439328416364549,
    -0.62485948814238634, -0.61523159058062682, -0.60551104140432555,
    -0.59569930449243336, -0.58579785745643886, -0.57580819141784534,
    -0.56573181078361312, -0.55557023301960218, -0.54532498842204646,
    -0.53499761988709715, -0.524589682678469, -0.51410274419322166,
    -0.50353838372571758, -0.49289819222978404, -0.48218377207912272,
    -0.47139673682599764, -0.46053871095824, -0.44961132965460654,
    -0.43861623853852766, -0.42755509343028208, -0.41642956009763715,
    -0.40524131400498986, -0.3939920400610481, -0.38268343236508978,
    -0.37131719395183749, -0.35989503653498811, -0.34841868024943456,
    -0.33688985339222005, -0.32531029216226293, -0.31368174039889152,
    -0.30200594931922808, -0.29028467725446233, -0.27851968938505306,
    -0.26671275747489837, -0.25486565960451457, -0.24298017990326387,
    -0.23105810828067111, -0.2191012401568698, -0.20711137619221856,
    -0.19509032201612825, -0.18303988795514095, -0.17096188876030122,
    -0.15885814333386145, -0.14673047445536175, -0.13458070850712617,
    -0.1224106751992162, -0.11022220729388306, -0.0980171403295606,
    -0.0857973123444399, -0.073564563599667426, -0.061320736302208578,
    -0.049067674327418015, -0.036807222941358832, -0.024541228522912288,
    -0.012271538285719925, -0.0 };

  int ihi;
  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 511; i++) {
    y[iy].re = x[ix];
    y[iy].im = 0.0;
    iy = 512;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy].re = x[ix];
  y[iy].im = 0.0;
  for (i = 0; i <= 511; i += 2) {
    temp_re = y[i + 1].re;
    temp_im = y[i + 1].im;
    y[i + 1].re = y[i].re - y[i + 1].re;
    y[i + 1].im = y[i].im - y[i + 1].im;
    y[i].re += temp_re;
    y[i].im += temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 128;
  iheight = 509;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re = y[i + iy].re;
      temp_im = y[i + iy].im;
      y[i + iy].re = y[i].re - temp_re;
      y[i + iy].im = y[i].im - temp_im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 256; j += ju) {
      twid_re = dv1[j];
      twid_im = dv2[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re = twid_re * y[i + iy].re - twid_im * y[i + iy].im;
        temp_im = twid_re * y[i + iy].im + twid_im * y[i + iy].re;
        y[i + iy].re = y[i].re - temp_re;
        y[i + iy].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix <<= 1;
    iheight -= iy;
  }
}

/*
 * File trailer for fft.c
 *
 * [EOF]
 */
