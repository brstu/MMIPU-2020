# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Linear_Model`](#class-linear_model) | class that implements Object of Control
`class `[`Model`](#class-model) | class that implements Object of Control
`class `[`Non_Linear_Model`](#class-non_linear_model) | class that implements Object of Control
`class `[`Regulator`](#class-regulator) | class that implements [Regulator](#class_regulator) Gr

# class `Linear_Model` 

```
class Linear_Model
  : public Model
```

class that implements Object of Control

this class extends parent class [Model](#class_model) and implements Linear [Model](#class_model)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Linear_Model`](#class_linear___model_1adb03244a651f6d5e580b07fc96e22b61)`(double a,double b)` | Constructor for NonLinearModel class 
`public inline virtual double `[`equation`](#class_linear___model_1a5aea196c08e6340f5451861fa140ee4d)`(double u_t,double y_t)` | it calculate Yt via linear method 

## Members

#### `public inline  `[`Linear_Model`](#class_linear___model_1adb03244a651f6d5e580b07fc96e22b61)`(double a,double b)` 

Constructor for NonLinearModel class 
#### Parameters
* `a` `b` coefficients

#### `public inline virtual double `[`equation`](#class_linear___model_1a5aea196c08e6340f5451861fa140ee4d)`(double u_t,double y_t)` 

it calculate Yt via linear method 
#### Parameters
* `y_t` output of [Regulator](#class_regulator)

* `u_t` input of [Regulator](#class_regulator)

#### Returns
input parameter to Object of Control Yt

# class `Model` 

class that implements Object of Control

abstract class to set needed functions

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`equation`](#class_model_1ac0c31a9467053bbb2584e89838c3305f)`(double u_t,double y_t)` | abstract function to override in child classes 

## Members

#### `public double `[`equation`](#class_model_1ac0c31a9467053bbb2584e89838c3305f)`(double u_t,double y_t)` 

abstract function to override in child classes 
#### Parameters
* `y_t` output of [Regulator](#class_regulator)

* `u_t` input of [Regulator](#class_regulator)

# class `Non_Linear_Model` 

```
class Non_Linear_Model
  : public Model
```

class that implements Object of Control

this class extends parent class [Model](#class_model) and implements Nonlinear [Model](#class_model)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Non_Linear_Model`](#class_non___linear___model_1a26e2de708c43ea3f5d34a6007f591012)`(double a,double b,double c,double d)` | Constructor for NonLinearModel class 
`public inline virtual double `[`equation`](#class_non___linear___model_1a2a702296269970e8adb1b85a2394d5fe)`(double u_t,double y_t)` | it calculate Yt via nonlinear method 

## Members

#### `public inline  `[`Non_Linear_Model`](#class_non___linear___model_1a26e2de708c43ea3f5d34a6007f591012)`(double a,double b,double c,double d)` 

Constructor for NonLinearModel class 
#### Parameters
* `a` `b` `c` `d` coefficients

#### `public inline virtual double `[`equation`](#class_non___linear___model_1a2a702296269970e8adb1b85a2394d5fe)`(double u_t,double y_t)` 

it calculate Yt via nonlinear method 
#### Parameters
* `y_t` output of [Regulator](#class_regulator)

* `u_t` input of [Regulator](#class_regulator)

#### Returns
input parameter to Object of Control Yt

# class `Regulator` 

class that implements [Regulator](#class_regulator) Gr

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#class_regulator_1af805ac469f8cb5935f3af9bd61ac8a77)`(double K,double T,double TD,double T0)` | Constructor for [Regulator](#class_regulator) class 
`public inline double `[`get_U_t`](#class_regulator_1aefa3eee81aff56431e842c380d154e25)`(double e,double e_0,double e_00)` | function that calculate u(t) and returns it
`public inline void `[`Start_PID_Regulator`](#class_regulator_1af341a9b2b305430b56c7bde657758843)`(double w,`[`Model`](#class_model)` * model,double y_t)` | function that models PID controller

## Members

#### `public inline  `[`Regulator`](#class_regulator_1af805ac469f8cb5935f3af9bd61ac8a77)`(double K,double T,double TD,double T0)` 

Constructor for [Regulator](#class_regulator) class 
#### Parameters
* `K` `T0` `TD` `T` coefficients

#### `public inline double `[`get_U_t`](#class_regulator_1aefa3eee81aff56431e842c380d154e25)`(double e,double e_0,double e_00)` 

function that calculate u(t) and returns it

#### Parameters
* `e` `e_0` `e_00` values of current, previous and the before previous one errors 

#### Returns
u_t u(t)

#### `public inline void `[`Start_PID_Regulator`](#class_regulator_1af341a9b2b305430b56c7bde657758843)`(double w,`[`Model`](#class_model)` * model,double y_t)` 

function that models PID controller

#### Parameters
* `w` some desired value 

* `*model` pointer on some [Model](#class_model) instance 

* `y_t` initial value of Yt
