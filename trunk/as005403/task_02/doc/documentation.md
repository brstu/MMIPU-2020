# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Linear`](#class_linear) | class that implements Object of Control this class extends parent class [Model](#class_model) and implements [Linear](#class_linear)[Model](#class_model)
`class `[`Model`](#class_model) | class that implements Object of Control abstract class to set needed functions
`class `[`NonLinear`](#class_non_linear) | class that implements Object of Control this class extends parent class [Model](#class_model) and implements Nonlinear [Model](#class_model)
`class `[`Regulator`](#class_regulator) | class that implements [Regulator](#class_regulator) Gr

# class `Linear` 

```
class Linear
  : public Model
```  

class that implements Object of Control this class extends parent class [Model](#class_model) and implements [Linear](#class_linear)[Model](#class_model)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Linear`](#class_linear_1af9240b9a16b1a4dd2c54b6037ad8d812)`(const float a,const float b,const double Y)` | Constructor for [Linear](#class_linear) class 
`public virtual float `[`equation`](#class_linear_1ad2f9696e2e5bc0ac885b74be3dcc9aa0)`(double U)` | it calculate Yt via linear method 

## Members

#### `public  `[`Linear`](#class_linear_1af9240b9a16b1a4dd2c54b6037ad8d812)`(const float a,const float b,const double Y)` 

Constructor for [Linear](#class_linear) class 
#### Parameters
* `a` `b` coefficients 

* `Y` initial value of Yt

#### `public virtual float `[`equation`](#class_linear_1ad2f9696e2e5bc0ac885b74be3dcc9aa0)`(double U)` 

it calculate Yt via linear method 
#### Parameters
* `ImputWarm` output of [Regulator](#class_regulator)

#### Returns
input parameter to Object of Control Yt

# class `Model` 

class that implements Object of Control abstract class to set needed functions

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`equation`](#class_model_1a61a6c8e015880cda9641b40ee265461f)`(double InputWarm)` | abstract function to override in child classes 

## Members

#### `public float `[`equation`](#class_model_1a61a6c8e015880cda9641b40ee265461f)`(double InputWarm)` 

abstract function to override in child classes 
#### Parameters
* `InputWarm` output of [Regulator](#class_regulator)

# class `NonLinear` 

```
class NonLinear
  : public Model
```  

class that implements Object of Control this class extends parent class [Model](#class_model) and implements Nonlinear [Model](#class_model)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NonLinear`](#class_non_linear_1a6d95678a56c3e96a6128386e80481f7a)`(const float a,const float b,const float c,const float d,const float Y)` | Constructor for NonLinearModel class 
`public virtual float `[`equation`](#class_non_linear_1a58fb6276569f4e8fc87eb3839e5a861a)`(double U)` | it calculate Yt via nonlinear method 

## Members

#### `public  `[`NonLinear`](#class_non_linear_1a6d95678a56c3e96a6128386e80481f7a)`(const float a,const float b,const float c,const float d,const float Y)` 

Constructor for NonLinearModel class 
#### Parameters
* `a` `b` `c` `d` coefficients 

* `Y` initial value of Yt

#### `public virtual float `[`equation`](#class_non_linear_1a58fb6276569f4e8fc87eb3839e5a861a)`(double U)` 

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
`public  `[`Regulator`](#class_regulator_1aedb45b9c3df014093c4991acd526a2bf)`(const double K,const double T0,const double TD,const double T)` | Constructor for [Regulator](#class_regulator) class 
`public double `[`get_Ut`](#class_regulator_1ae9357fa5def536fbcbe6e9da3089ea6e)`(const double E,const double E0,const double E0prev)` | function that calculate u(t) and returns it
`public void `[`PIDRegulator`](#class_regulator_1a65ab24d76cd9869504294cffd71366c3)`(const double w,`[`Regulator`](#class_regulator)` * reg,`[`Model`](#class_model)` * lm,double Yinit)` | function that simulates a PID controller and outputs in .csv file the results

## Members

#### `public  `[`Regulator`](#class_regulator_1aedb45b9c3df014093c4991acd526a2bf)`(const double K,const double T0,const double TD,const double T)` 

Constructor for [Regulator](#class_regulator) class 
#### Parameters
* `K` `T0` `TD` `T` coefficients

#### `public double `[`get_Ut`](#class_regulator_1ae9357fa5def536fbcbe6e9da3089ea6e)`(const double E,const double E0,const double E0prev)` 

function that calculate u(t) and returns it

#### Parameters
* `E` `E0` `E0prev` values of current, previous and the before previous one errors 

#### Returns
InputWarm u(t)

#### `public void `[`PIDRegulator`](#class_regulator_1a65ab24d76cd9869504294cffd71366c3)`(const double w,`[`Regulator`](#class_regulator)` * reg,`[`Model`](#class_model)` * lm,double Yinit)` 

function that simulates a PID controller and outputs in .csv file the results

#### Parameters
* `w` some desired value 

* `*reg` pointer on [Regulator](#class_regulator) instance 

* `*lm` pointer on some [Model](#class_model) instance 

* `Yinit` initial value of Yt

Generated by [Moxygen](https://sourcey.com/moxygen)