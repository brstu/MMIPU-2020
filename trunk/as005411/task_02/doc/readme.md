# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`main`](#main_8cpp_1ae66f6b31b5ad750f1fe042a706a4e3d4)`()`            | 
`class `[`controlobject`](#classcontrolobject) | Abstract class that contains common controlled object logic.
`class `[`linear`](#classlinear) | Linear controlled object logic.
`class `[`model`](#classmodel) | Controlled system model.
`class `[`nonlinear`](#classnonlinear) | Noninear controlled object logic.
`class `[`regulator`](#classregulator) | Regulator logic class.

## Members

#### `public int `[`main`](#main_8cpp_1ae66f6b31b5ad750f1fe042a706a4e3d4)`()` 

# class `controlobject` 

Abstract class that contains common controlled object logic.

This class contains common variables and methods(mostly abstract) with some additional useful logic such as copyconstructors and other.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`controlobject`](#classcontrolobject_1aaf1d48a4ab64888c373a67e0108c2b02)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` | Abstract class for control object implementation.
`public `[`controlobject`](#classcontrolobject)` & `[`operator=`](#classcontrolobject_1a3cb284468043979c03e3e79f05fc7e01)`(const `[`controlobject`](#classcontrolobject)` *& other)` | 
`public  `[`controlobject`](#classcontrolobject_1a35efcd77e51347fe5d605d7346598357)`(`[`controlobject`](#classcontrolobject)` *& other)` | 
`public double & `[`eq`](#classcontrolobject_1abfcc12bc5f2fe4fffa7285c92d5c29e6)`(const double & iu)` | Common pure virtual method with slightly different logic for linear and nonlinear objects.
`protected double `[`a`](#classcontrolobject_1a286278950a0b3f0841962df6eaa1011d) | 
`protected double `[`b`](#classcontrolobject_1adb85b85e25d3ac9f38e412449e9182c9) | 
`protected double `[`c`](#classcontrolobject_1aec6f5a50a89d0bef3825342667ca265b) | 
`protected double `[`d`](#classcontrolobject_1a22d40ab89d292a4adac6a511b130a9b3) | 
`protected double `[`y`](#classcontrolobject_1aecd18dbc37806ff75770821de0206301) | 

## Members

#### `public  `[`controlobject`](#classcontrolobject_1aaf1d48a4ab64888c373a67e0108c2b02)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` 

Abstract class for control object implementation.

Constructor for controlled object. Initializes needed variables and stuff.

This class contains common variables and methods(mostly abstract) with some additional useful logic such as copyconstructors and other.

#### `public `[`controlobject`](#classcontrolobject)` & `[`operator=`](#classcontrolobject_1a3cb284468043979c03e3e79f05fc7e01)`(const `[`controlobject`](#classcontrolobject)` *& other)` 

#### `public  `[`controlobject`](#classcontrolobject_1a35efcd77e51347fe5d605d7346598357)`(`[`controlobject`](#classcontrolobject)` *& other)` 

#### `public double & `[`eq`](#classcontrolobject_1abfcc12bc5f2fe4fffa7285c92d5c29e6)`(const double & iu)` 

Common pure virtual method with slightly different logic for linear and nonlinear objects.

#### `protected double `[`a`](#classcontrolobject_1a286278950a0b3f0841962df6eaa1011d) 

#### `protected double `[`b`](#classcontrolobject_1adb85b85e25d3ac9f38e412449e9182c9) 

#### `protected double `[`c`](#classcontrolobject_1aec6f5a50a89d0bef3825342667ca265b) 

#### `protected double `[`d`](#classcontrolobject_1a22d40ab89d292a4adac6a511b130a9b3) 

#### `protected double `[`y`](#classcontrolobject_1aecd18dbc37806ff75770821de0206301) 

# class `linear` 

```
class linear
  : protected controlobject
```

Linear controlled object logic.

Class that contains linear controlled object logic.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`linear`](#classlinear_1a8d519b6157a7409728647e8b6963de50)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` | Linear controlled object logic implementation.
`public virtual double & `[`eq`](#classlinear_1a6c4e69ac069a74a23f7debb3cba809ce)`(const double & iu)` | Method that contains primary logic of linear controlled object.

## Members

#### `public  `[`linear`](#classlinear_1a8d519b6157a7409728647e8b6963de50)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` 

Linear controlled object logic implementation.

Constructor for linear controlled object. Initializes needed variables and stuff.

Class that contains implementation for linear controlled object logic.

#### `public virtual double & `[`eq`](#classlinear_1a6c4e69ac069a74a23f7debb3cba809ce)`(const double & iu)` 

Method that contains primary logic of linear controlled object.

# class `model` 

Controlled system model.

This class contains our model with its modules(regulators, etc.).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`model`](#classmodel_1a3f1a317836ec9dc83854be7e15b078a2)`(const double & iu,const double & iy,const double & tq)` | Controlled system model implementation.
`public bool `[`initmodules`](#classmodel_1a1ed03e7058319f3bbb95d511853630f8)`(`[`linear`](#classlinear)` *& l,`[`nonlinear`](#classnonlinear)` *& n,`[`regulator`](#classregulator)` *& r)` | Method for modules(objects) initialization. It exists because i wanted this program to be modular not monolythic.
`public double `[`active`](#classmodel_1a1e887c59b11d41b1ff59fac1ac611100)`()` | Method for starting our model, and calculating its working variables.

## Members

#### `public  `[`model`](#classmodel_1a3f1a317836ec9dc83854be7e15b078a2)`(const double & iu,const double & iy,const double & tq)` 

Controlled system model implementation.

Constructor for our model with some needed values.

This class contains implementation of the logic of model with its modules(regulators, etc.).

#### `public bool `[`initmodules`](#classmodel_1a1ed03e7058319f3bbb95d511853630f8)`(`[`linear`](#classlinear)` *& l,`[`nonlinear`](#classnonlinear)` *& n,`[`regulator`](#classregulator)` *& r)` 

Method for modules(objects) initialization. It exists because i wanted this program to be modular not monolythic.

#### Parameters
* `l` Passed control object with linear logic 

* `n` Passed control object with non-linear logic. 

* `r` Passed regulator object.

#### `public double `[`active`](#classmodel_1a1e887c59b11d41b1ff59fac1ac611100)`()` 

Method for starting our model, and calculating its working variables.

# class `nonlinear` 

```
class nonlinear
  : public controlobject
```

Noninear controlled object logic.

Class that contains nonlinear controlled object logic.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`nonlinear`](#classnonlinear_1af34574cf5a3e0007808d662b7e010fe5)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` | Noninear controlled object logic implementation.
`public virtual double & `[`eq`](#classnonlinear_1af14c9c06ecca95f31e1814f20b0723a6)`(const double & iu)` | Method that contains primary logic of nonlinear controlled object.

## Members

#### `public  `[`nonlinear`](#classnonlinear_1af34574cf5a3e0007808d662b7e010fe5)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` 

Noninear controlled object logic implementation.

Constructor for nonlinear controlled object. Initializes needed variables and stuff.

Class that contains implementation for nonlinear controlled object logic.

#### `public virtual double & `[`eq`](#classnonlinear_1af14c9c06ecca95f31e1814f20b0723a6)`(const double & iu)` 

Method that contains primary logic of nonlinear controlled object.

# class `regulator` 

Regulator logic class.

This class contains Regulator logic.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`regulator`](#classregulator_1a145f2b6f37cfa129905c50c992d2c018)`(const double & qt)` | Regulator logic implementation class.
`public  `[`regulator`](#classregulator_1adb39ebc41d04c32d43e6d692f09c31c4)`(const double & qt,const double & ik)` | Constructor for only K variable specified.
`public  `[`regulator`](#classregulator_1ad1d74446461fead9d6ba1be61c3f07f9)`(const double & qt,const double & ik,const double & it)` | Constructor for variables K and T specified.
`public  `[`regulator`](#classregulator_1aee66beb7839d42beb5aa6c87d583d0b0)`(const double & qt,const double & ik,const double & it,const double & itd)` | Constructor for all variables specified. It also calculates all consts in process.
`public double & `[`eq`](#classregulator_1a73c385c032fcd8dc4d42ef5030e6f999)`(const double & iek)` | Primary regulator logic function.

## Members

#### `public  `[`regulator`](#classregulator_1a145f2b6f37cfa129905c50c992d2c018)`(const double & qt)` 

Regulator logic implementation class.

Constructor for unspecified variables.

This class contains Regulator logic implementation.

#### `public  `[`regulator`](#classregulator_1adb39ebc41d04c32d43e6d692f09c31c4)`(const double & qt,const double & ik)` 

Constructor for only K variable specified.

#### `public  `[`regulator`](#classregulator_1ad1d74446461fead9d6ba1be61c3f07f9)`(const double & qt,const double & ik,const double & it)` 

Constructor for variables K and T specified.

#### `public  `[`regulator`](#classregulator_1aee66beb7839d42beb5aa6c87d583d0b0)`(const double & qt,const double & ik,const double & it,const double & itd)` 

Constructor for all variables specified. It also calculates all consts in process.

#### `public double & `[`eq`](#classregulator_1a73c385c032fcd8dc4d42ef5030e6f999)`(const double & iek)` 

Primary regulator logic function.

This function contains primary logic with needed value returned. 
#### Parameters
* `iek` Input value e(k)

Generated by [Moxygen](https://sourcey.com/moxygen)