# Summary

Members                                       |     Descriptions                           |
----------------------------------------------|--------------------------------------------|
`class `[`Lineir`](#class-lineir)             |     Linear function class.                 |
`class `[`Model`](#class-model)               |     Main abstract class.                   |
`class `[`NonLineir`](#class-nonlineir)       |     NonLineer function class.              |
`class `[`Regulator`](#class-regulator)       |     [Regulator](#class-regulator) class.   |



class Lineir

```
class Lineir
: public Model
```

Linear function class.

It's a linear function class which include method for calculate linear function.

## Summary

Members                                                                           |   Descriptions                              |
----------------------------------------------------------------------------------|---------------------------------------------|
`public inline `[`Lineir`](#class-lineirfun)`(float a,float b)`                   |   Constructor for Linear function class     |
`public inline virtual float `[`equation`](#class-lineir)`(float ut,float yt)`    |   This function calculates our linear model |

## Members

#### `public inline `[`Lineir`](#class-lineir)`(float a,float b)`

Constructor for Linear function class

#### Parameters

* `a` `b` coefficients

#### `public inline virtual float `[`equation`](#class-lineir)`(float ut,float yt)`

This function calculates our linear model
#### Parameters
* `yt` Input Warm

* `ut` Output variable

#### Returns
ut calculated value

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

Members                                                         |    Descriptions                                                  |
----------------------------------------------------------------|------------------------------------------------------------------|
`public float `[`equation`](#class-model)`(float ut,float y0)`  |    This is virtual method which other classes need for implement |

## Members

#### `public float `[`equation`](#class-model)`(float ut,float y0)`

This is virtual method which other classes need for implement
#### Parameters
* `ut` Input Warm

* `yo` Output value

# class `NonLineir`

```
class NonLineir
: public Model
```

NonLineer function class.

This is nonlinear function class which include method for calculate nonlinear function.

## Summary

Members                                                                                  |    Descriptions                                  |
-----------------------------------------------------------------------------------------|--------------------------------------------------|
`public inline `[`NonLineirFun`](#class-nonlineirfun)`(float a,float b,float c,float d)` |    Constructor for Nonlinear function class      |
`public inline virtual float `[`equation`](#class-nonlineirfun)`(float ut,float yt)`     |    This function calculates our nonlinear model  |

## Members

#### `public inline `[`NonLineir`](#class-nonlineir)`(float a,float b,float c,float d)`

Constructor for Nonlinear function class
#### Parameters
* `a` `b` `c` `d` coefficients

#### `public inline virtual float `[`equation`](#class-nonlineir)`(float ut,float yt)`

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

[Regulator](#class-regulator) class.

This is [Regulator](#class-regulator) class which include method for calculate input warm(ut)

## Summary
 
Members                                                                                       |    Descriptions                                   |
----------------------------------------------------------------------------------------------|---------------------------------------------------|
`public inline `[`Regulator`](#class-regulator)`(float wt,float TD,float T0,float T,float K)` |    Constructor for [Regulator](#class-regulator)  |
`public inline float `[`calculateUt`](#class-regulator)`(float yt,ofstream & file)`           |    This function calculates our linear model      |

## Members

#### `public inline `[`Regulator`](#class-regulator)`(float wt,float TD,float T0,float T,float K)`

Constructor for [Regulator](#class-regulator)
 
#### Parameters
* `TD` `TO` `T` `K` coefficients

* `wt` desired value

#### `public inline float `[`calculateUt`](#class-regulator)`(float yt,ofstream & file)`

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
file « "," « ek « endl;
ek = wt - yt;
ut += (q0 * ek) + (q1 * ek1) + (q2 * ek2);
ek2 = ek1;
ek1 = ek;
return ut;
}
```

Generated by [Moxygen](https://sourcey.com/moxygen)
