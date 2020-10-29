# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`LineirFun`](#class_lineirfun) | Linear function class.
`class `[`Model`](#class_model) | Main abstract class.
`class `[`NonLineirFun`](#class_nonlineirfun) | NonLineer function class.
`class `[`Regulator`](#class_regulator) | [Regulator](#class_regulator) class.

# class `LineirFun` 

```
class LineirFun
  : public Model
```

Linear function class.

It's a linear function class which include method for calculate linear function.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LineirFun`](#class_lineir_fun_1a5f7c51a7e6b032f00e43796f8bd80b04)`(float a,float b)` | Constructor for Linear function class 
`public inline virtual float `[`equation`](#class_lineir_fun_1a7ed38c11cd386e07657f32d858e6c9ba)`(float ut,float yt)` | This function calculates our linear model 

## Members

#### `public inline  `[`LineirFun`](#class_lineir_fun_1a5f7c51a7e6b032f00e43796f8bd80b04)`(float a,float b)` 

Constructor for Linear function class 
#### Parameters
* `a` `b` coefficients

#### `public inline virtual float `[`equation`](#class_lineir_fun_1a7ed38c11cd386e07657f32d858e6c9ba)`(float ut,float yt)` 

This function calculates our linear model 
#### Parameters
* `ut` Input Warm 

* `yt` Output variable 

#### Returns
yt calculated value

Function code: 
```cpp
float equation(float ut,float yt) override {
      return yt = a * yt + b * ut;
    }
```

# class `Model` 

Main abstract class.

This is abstract class which include virtual method for chield's classes.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`equation`](#class_model_1ae4679a6c3c770b1b66621f95d53566d9)`(float ut,float y0)` | This is virtual method which other classes need for implement 

## Members

#### `public float `[`equation`](#class_model_1ae4679a6c3c770b1b66621f95d53566d9)`(float ut,float y0)` 

This is virtual method which other classes need for implement 
#### Parameters
* `ut` Input Warm 

* `yo` Output value

# class `NonLineirFun` 

```
class NonLineirFun
  : public Model
```

NonLineer function class.

This is nonlinear function class which include method for calculate nonlinear function.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonLineirFun`](#class_non_lineir_fun_1a2ceea0cb312ae84ce5a866b4ec757e9c)`(float a,float b,float c,float d)` | Constructor for Nonlinear function class 
`public inline virtual float `[`equation`](#class_non_lineir_fun_1a143ef18fce91f54c6d9087ef53c166f2)`(float ut,float yt)` | This function calculates our nonlinear model 

## Members

#### `public inline  `[`NonLineirFun`](#class_non_lineir_fun_1a2ceea0cb312ae84ce5a866b4ec757e9c)`(float a,float b,float c,float d)` 

Constructor for Nonlinear function class 
#### Parameters
* `a` `b` `c` `d` coefficients

#### `public inline virtual float `[`equation`](#class_non_lineir_fun_1a143ef18fce91f54c6d9087ef53c166f2)`(float ut,float yt)` 

This function calculates our nonlinear model 
#### Parameters
* `ut` Input Warm 

* `yt` Output variable 

#### Returns
yt calculated value

Function code: 
```cpp
float equation(float ut, float yt) override {
    y = yt;
    yt = a * y - b * pow(prevY, 2) + c * ut + d * sin(ut1);
    ut1 = ut;
    prevY = y;
    return yt;
}
```

# class `Regulator` 

[Regulator](#class_regulator) class.

This is [Regulator](#class_regulator) class which include method for calculate input warm(ut)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#class_regulator_1af3732f7a7badaf070e9ff4f67943f6ec)`(float wt,float TD,float T0,float T,float K)` | Constructor for [Regulator](#class_regulator)
`public inline float `[`calculateUt`](#class_regulator_1af40765881b701abfa6c467acb48106e4)`(float yt,ofstream & file)` | This function calculates our linear model 

## Members

#### `public inline  `[`Regulator`](#class_regulator_1af3732f7a7badaf070e9ff4f67943f6ec)`(float wt,float TD,float T0,float T,float K)` 

Constructor for [Regulator](#class_regulator)
#### Parameters
* `TD` `TO` `T` `K` coefficients 

* `wt` desired value

#### `public inline float `[`calculateUt`](#class_regulator_1af40765881b701abfa6c467acb48106e4)`(float yt,ofstream & file)` 

This function calculates our linear model 
#### Parameters
* `ut` Input Warm(calculated value) 

* `&file` It's a file for construct Excel table 

#### Returns
ut calculated value

Function code: 
```cpp
float calculateUt(float yt, ofstream &file) {
    float q0 = K * (1.0 + (TD / T0));
    float q1 = -K * (1.0 + (2.0 * TD / T0) - (T0 / T));
    float q2 = K * (TD / T0);
    file << "," << ek << endl;
    ek = wt - yt;
    ut += (q0 * ek) + (q1 * ek1) + (q2 * ek2);
    ek2 = ek1;
    ek1 = ek;
    return ut;
}
```

Generated by [Moxygen](https://sourcey.com/moxygen)