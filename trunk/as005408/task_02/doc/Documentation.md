# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`LinearModel`](#class-LinearModel ) | class that implements Object of Control
`class `[`Model`](#class-Model) | class that implements Object of Control
`class `[`NonLinearModel`](#class-NonLinearModel ) | class that implements Object of Control
`class `[`Regulator`](#class-Regulator) | class that implements [Regulator](#class-Regulator) Gr

# class `LinearModel` 

```
class LinearModel
  : public Model
```  

class that implements Object of Control

this class extends parent class [Model](#class-model) and implements Linear [Model](#class-model)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearModel`](#class_linear_model_1ac55488370c5ad720b687ff893c9c340e)`(const float a,const float b,const double Y)` | Constructor for [NonLinearModel](#class_non_linear_model) class 
`public inline virtual float `[`equation`](#class_linear_model_1a810809f4762e7cb987a3ba5c8bfb9b50)`(double InputWarm)` | it calculate Yt via linear method 

## Members

#### `public inline  `[`LinearModel`](#class_linear_model_1ac55488370c5ad720b687ff893c9c340e)`(const float a,const float b,const double Y)` 

Constructor for [NonLinearModel](#class-NonLinearModel) class 
#### Parameters
* `a` `b` coefficients 

* `Y` initial value of Yt

#### `public inline virtual float `[`equation`](#class_linear_model_1a810809f4762e7cb987a3ba5c8bfb9b50)`(double InputWarm)` 

it calculate Yt via linear method 
#### Parameters
* `ImputWarm` output of [Regulator](#class_regulator)

#### Returns
input parameter to Object of Control Yt

# class `Model` 

class that implements Object of Control

abstract class to set needed functions

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`equation`](#class_model_1a61a6c8e015880cda9641b40ee265461f)`(double InputWarm)` | abstract function to override in child classes 

## Members

#### `public float `[`equation`](#class_model_1a61a6c8e015880cda9641b40ee265461f)`(double InputWarm)` 

abstract function to override in child classes 
#### Parameters
* `InputWarm` output of [Regulator](#class_regulator)

# class `NonLinearModel` 

```
class NonLinearModel
  : public Model
```  

class that implements Object of Control

this class extends parent class [Model](#class-model) and implements Nonlinear [Model](#class-model)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonLinearModel`](#class_non_linear_model_1a23a67b94f7bf70e7c1034cdfe758969b)`(const float a,const float b,const float c,const float d,const float Y)` | Constructor for [NonLinearModel](#class_non_linear_model) class 
`public inline virtual float `[`equation`](#class_non_linear_model_1acd60f85f5a8421a492bf5d0dcf244f1d)`(double InputWarm)` | it calculate Yt via nonlinear method 

## Members

#### `public inline  `[`NonLinearModel`](#class_non_linear_model_1a23a67b94f7bf70e7c1034cdfe758969b)`(const float a,const float b,const float c,const float d,const float Y)` 

Constructor for [NonLinearModel](#class_non_linear_model) class 
#### Parameters
* `a` `b` `c` `d` coefficients 

* `Y` initial value of Yt

#### `public inline virtual float `[`equation`](#class_non_linear_model_1acd60f85f5a8421a492bf5d0dcf244f1d)`(double InputWarm)` 

it calculate Yt via nonlinear method 
#### Parameters
* `ImputWarm` output of [Regulator](#class_regulator)

#### Returns
input parameter to Object of Control Yt

# class `Regulator` 

class that implements [Regulator](#class_regulator) Gr

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#class_regulator_1aedb45b9c3df014093c4991acd526a2bf)`(const double K,const double T0,const double TD,const double T)` | Constructor for [Regulator](#class_regulator) class 
`public inline double `[`getImputWarm`](#class_regulator_1a19442d8a09ec33720bfc002d08122e14)`(const double E,const double Eprev,const double Eprevprev)` | function that calculate u(t) and returns it

## Members

#### `public inline  `[`Regulator`](#class_regulator_1aedb45b9c3df014093c4991acd526a2bf)`(const double K,const double T0,const double TD,const double T)` 

Constructor for [Regulator](#class_regulator) class 
#### Parameters
* `K` `T0` `TD` `T` coefficients

#### `public inline double `[`getImputWarm`](#class_regulator_1a19442d8a09ec33720bfc002d08122e14)`(const double E,const double Eprev,const double Eprevprev)` 

function that calculate u(t) and returns it

#### Parameters
* `E` `Eprev` `Eprevprev` values of current, previous and the before previous one errors 

#### Returns
InputWarm u(t)