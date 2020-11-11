# Summary

Members                                       |     Descriptions                           |
----------------------------------------------|--------------------------------------------|
`class `[`lineir`](#class-lineir)             |     Linear function class.                 |
`class `[`model`](#class-model)               |     Main abstract class.                   |
`class `[`nonlineir`](#class-nonlineir)       |     NonLineer function class.              |
`class `[`regulator`](#class-regulator)       |     [regulator](#class-regulator) class.   |



class lineir

```
class Lineir
: public model
```

Linear function class.

It's a linear function class which include method for calculate linear function.

## Summary

Members                                                                           |   Descriptions                              |
----------------------------------------------------------------------------------|---------------------------------------------|
`public inline `[`lineir`](#class-lineir)`(float a,float b)`                      |   Constructor for Linear function class     |
`public inline virtual float `[`equation`](#class-lineir)`(float ut,float yt)`    |   This function calculates our linear model |

## Members

#### `public inline `[`lineir`](#class-lineir)`(float a,float b,float yt_1)`

Constructor for Linear function class

#### Parameters

* `a` `b` coefficients

#### `public inline virtual float `[`equation`](#class-lineir)`(float yt,float ut)`

This function calculates our linear model
#### Parameters
* `yt` Input Warm

* `ut` Output variable

#### Returns
yt_1 calculated value

Function code:
```cpp
float equation(float yt,float ut) override {
yt_1 = a * yt + b * ut;
return yt_1
}
```

# class `model`

Main abstract class.

This is abstract class which include virtual method for chield's classes.

## Summary

Members                                                         |    Descriptions                                                  |
----------------------------------------------------------------|------------------------------------------------------------------|
`public float `[`equation`](#class-model)`(float ut,float y0)`  |    This is virtual method which other classes need for implement |

## Members

#### `public float `[`equation`](#class-model)`(float ut,float ut)`

This is virtual method which other classes need for implement
#### Parameters
* `yt` Input Warm

* `ut` Output value

# class `nonLineir`

```
class nonlineir
: public model
```

NonLineer function class.

This is nonlinear function class which include method for calculate nonlinear function.

## Summary

Members                                                                                  |    Descriptions                                  |
-----------------------------------------------------------------------------------------|--------------------------------------------------|
`public inline `[`nonlineir`](#class-nonlineir)`(float a,float b,float c,float d)` |    Constructor for Nonlinear function class      |
`public inline virtual float `[`equation`](#class-nonlineirfun)`(float yt,float ut)`     |    This function calculates our nonlinear model  |

## Members

#### `public inline `[`nonlineir`](#class-nonlineir)`(float a,float b,float c,float d)`

Constructor for Nonlinear function class
#### Parameters
* `a` `b` `c` `d` coefficients

#### `public inline virtual float `[`equation`](#class-nonlineir)`(float yt,float ut)`

This function calculates our nonlinear model
#### Parameters
* `yt` Input Warm

* `ut` Output variable

#### Returns
yt_1 calculated value

Function code:
```cpp
float equation(float ut, float yt) {
yt_1 = a * yt - b * pow(yt_0, 2) + c * ut + d * sin(ut_0);
        ut_0 = ut;
        yt_0 = yt;
        yt = yt_1;

        return yt_1;
}
```

# class `regulator`

[regulator](#class-regulator) class.

This is [regulator](#class-regulator) class which include method for calculate input warm(ut)

## Summary
 
Members                                                                                       |    Descriptions                                   |
----------------------------------------------------------------------------------------------|---------------------------------------------------|
`public inline `[`regulator`](#class-regulator)`(float T,float TD,float T0,float yt_1,float K)` |    Constructor for [regulator](#class-regulator)  |
`public inline float `[`calculateUt`](#class-regulator)`(float yt,ofstream & file)`           |    This function calculates our linear model      |

## Members

#### `public inline `[`regulator`](#class-regulator)`(float yt_1,float TD,float T0,float T,float K)`

Constructor for [regulator](#class-regulator)
 
#### Parameters
* `TD` `TO` `T` `K` coefficients

* `yt_1` desired value

#### `public inline float `[`calculateUt`](#class-regulator)`(float yt)`

This function calculates our linear model
#### Parameters
* `e` `em1` `em2` Input Warm(calculated value)

#### Returns
yt_1 calculated value

Function code:
```cpp
 float warm(float e, float em1, float em2) {

        float q0 = K * (1 + TD / T0);
        float q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        float q2 = K * TD / T0;
        
        yt_1 += q0 * e + q1 * em1 + q2 * em2;
   
        return yt_1;
}
```

Generated by [Moxygen](https://sourcey.com/moxygen)
