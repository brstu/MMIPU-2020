# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`main`](#main)`()`            | 
`class `[`Ctrl`](#class-Ctrl) | Abstract class that contains common controlled object logic.
`class `[`Lin`](#class-Lin) | Linear controlled object logic.
`class `[`Mod`](#class-Mod) | Controlled system model.
`class `[`NoLin`](#class-NoLin) | Non-linear controlled object logic. 
`class `[`Rgl`](#class-Rgl) | Regulator logic class.

## Members

#### `public int `[`main`](#main)`()` 

# class `Ctrl` 

Abstract class that contains common controlled object logic.

This class contains common variables and methods(mostly abstract) with some additional useful logic such as copy-constructors and other.

## Summary

 Members                                                      | Descriptions                                                 
 ------------------------------------------------------------ | ------------------------------------------------------------ 
 `public  `[`Ctrl`](#public--Ctrlconst-double--iaconst-double--ibconst-double--icconst-double--idconst-double--iy)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` | Abstract class for control object implementation.            
 `public `[`Ctrl`](#class-Ctrl)` & `[`operator=`](#public-Ctrloperatorconst-Ctrl--other)`(const `[`Ctrl`](#class-Ctrl)` *& other)` |                                                              
 `public  `[`Ctrl`](#public--CtrlCtrl--other)`(`[`Ctrl`](#class-Ctrl)` *& other)` |                                                              
 `public double & `[`eq`](#public-double--eqconst-double--iu)`(const double & iu)` | Common pure virtual method with slightly different logic for lin and nonlin objects. 
 `protected double `[`a`](#protected-double-a)                |                                                              
 `protected double `[`b`](#protected-double-b)                |                                                              
 `protected double `[`c`](#protected-double-c)                |                                                              
 `protected double `[`d`](#protected-double-d)                |                                                              
 `protected double `[`y`](#protected-double-y)                |                                                              

## Members

#### `public  `[`Ctrl`](#public--Ctrlconst-double--iaconst-double--ibconst-double--icconst-double--idconst-double--iy)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` 

Abstract class for control object implementation.

Constructor for controlled object. Initializes needed variables and stuff.

This class contains common variables and methods(mostly abstract) with some additional useful logic such as copy-constructors and other.

#### `public `[`Ctrl`](#class-Ctrl)` & `[`operator=`](#public-Ctrloperatorconst-Ctrl--other)`(const `[`Ctrl`](#class-Ctrl)` *& other)` 

#### `public  `[`Ctrl`](#public--CtrlCtrl--other)`(`[`Ctrl`](#class-Ctrl)` *& other)` 

#### `public double & `[`eq`](#public-double--eqconst-double--iu)`(const double & iu)` 

Common pure virtual method with slightly different logic for linear and nonlinear objects.

#### `protected double `[`a`](#protected-double-a) 

#### `protected double `[`b`](#protected-double-b) 

#### `protected double `[`c`](#protected-double-c) 

#### `protected double `[`d`](#protected-double-d) 

#### `protected double `[`y`](#protected-double-y) 

# class `Lin` 

```
class Lin
  : protected Ctrl
```

Linear controlled object logic.

Class that contains linear controlled object logic.

## Summary

 Members                                                      | Descriptions                                                 
 ------------------------------------------------------------ | ------------------------------------------------------------ 
 `public  `[`Lin`](#public--Linconst-double--iaconst-double--ibconst-double--icconst-double--idconst-double--iy)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` | Linear controlled object logic implementation.               
 `public virtual double & `[`eq`](#public-virtual-double--eqconst-double--iu)`(const double & iu)` | Method that contains primary logic of linear controlled object. 

## Members

#### `public  `[`Lin`](#public--Linconst-double--iaconst-double--ibconst-double--icconst-double--idconst-double--iy)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` 

Linear controlled object logic implementation.

Constructor for linear controlled object. Initializes needed variables and stuff.

Class that contains implementation for linear controlled object logic.

#### `public virtual double & `[`eq`](#public-virtual-double--eqconst-double--iu)`(const double & iu)` 

Method that contains primary logic of linear controlled object.

# class `Mod` 

Controlled system model.

This class contains our model with its modules(regulators, etc.).

## Summary

 Members                                                      | Descriptions                                                 
 ------------------------------------------------------------ | ------------------------------------------------------------ 
 `public  `[`Mod`](#public--Modconst-double--iuconst-double--iyconst-double--tq)`(const double & iu,const double & iy,const double & tq)` | Controlled system model implementation.                      
 `public bool `[`initmodules`](#public-bool-initmodulesLin--lNoLin--nRgl--r)`(`[`Lin`](#class-Lin)` *& l,`[`NoLin`](#class-NoLin)` *& n,`[`Rgl`](#class-Rgl)` *& r)` | Method for modules(objects) initialization. It exists because I wanted this program to be modular not monolithic. 
 `public double `[`active`](#public-double-active)`()`        | Method for starting our model, and calculating its working variables. 

## Members

#### `public  `[`Mod`](#public--Modconst-double--iuconst-double--iyconst-double--tq)`(const double & iu,const double & iy,const double & tq)` 

Controlled system model implementation.

Constructor for our model with some needed values.

This class contains implementation of the logic of model with its modules(regulators, etc.).

#### `public bool `[`initmodules`](#public-bool-initmodulesLin--lNoLin--nRgl--r)`(`[`Lin`](#class-Lin)` *& l,`[`NoLin`](#class-NoLin)` *& n,`[`Rgl`](#class-Rgl)` *& r)` 

Method for modules(objects) initialization. It exists because i wanted this program to be modular not monolithic.

#### Parameters
* `l` Passed control object with linear logic 

* `n` Passed control object with non-linear logic. 

* `r` Passed regulator object.

#### `public double `[`active`](#public-double-active)`()` 

Method for starting our model, and calculating its working variables.

# class `NoLin` 

```
class NoLin
  : public Ctrl
```

Nonlinear controlled object logic.

Class that contains nonlinear controlled object logic.

## Summary

 Members                                                      | Descriptions                                                 
 ------------------------------------------------------------ | ------------------------------------------------------------ 
 `public  `[`NoLin`](#public--NoLinconst-double--iaconst-double--ibconst-double--icconst-double--idconst-double--iy)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` | Nonlinear controlled object logic implementation.            
 `public virtual double & `[`eq`](#public-virtual-double--eqconst-double--iu-1)`(const double & iu)` | Method that contains primary logic of NoLin controlled object. 

## Members

#### `public  `[`NoLin`](#public--NoLinconst-double--iaconst-double--ibconst-double--icconst-double--idconst-double--iy)`(const double & ia,const double & ib,const double & ic,const double & id,const double & iy)` 

Nonlinear controlled object logic implementation.

Constructor for nonlinear controlled object. Initializes needed variables and stuff.

Class that contains implementation for nonlinear controlled object logic.

#### `public virtual double & `[`eq`](#public-virtual-double--eqconst-double--iu-1)`(const double & iu)` 

Method that contains primary logic of nonlinear controlled object.

# class `Rgl` 

Regulator logic class.

This class contains Regulator logic.

## Summary

 Members                                                      | Descriptions                                                 
 ------------------------------------------------------------ | ------------------------------------------------------------ 
 `public  `[`Rgl`](#public--Rglconst-double--qt)`(const double & qt)` | Regulator logic implementation class.                        
 `public  `[`Rgl`](#public--Rglconst-double--qtconst-double--ik)`(const double & qt,const double & ik)` | Constructor for only K variable specified.                   
 `public  `[`Rgl`](#public--Rglconst-double--qtconst-double--ikconst-double--it)`(const double & qt,const double & ik,const double & it)` | Constructor for variables K and T specified.                 
 `public  `[`Rgl`](#public--Rglconst-double--qtconst-double--ikconst-double--itconst-double--itd)`(const double & qt,const double & ik,const double & it,const double & itd)` | Constructor for all variables specified. It also calculates all consts in process. 
 `public double & `[`eq`](#public-double--eqconst-double--iek)`(const double & iek)` | Primary regulator logic function.                            

## Members

#### `public  `[`Rgl`](#public--Rglconst-double--qt)`(const double & qt)` 

Regulator logic implementation class.

Constructor for unspecified variables.

This class contains Regulator logic implementation.

#### `public  `[`Rgl`](#public--Rglconst-double--qtconst-double--ik)`(const double & qt,const double & ik)` 

Constructor for only K variable specified.

#### `public  `[`Rgl`](#public--Rglconst-double--qtconst-double--ikconst-double--it)`(const double & qt,const double & ik,const double & it)` 

Constructor for variables K and T specified.

#### `public  `[`Rgl`](#public--Rglconst-double--qtconst-double--ikconst-double--itconst-double--itd)`(const double & qt,const double & ik,const double & it,const double & itd)` 

Constructor for all variables specified. It also calculates all consts in process.

#### `public double & `[`eq`](#public-double--eqconst-double--iek)`(const double & iek)` 

Primary regulator logic function.

This function contains primary logic with needed value returned. 
#### Parameters
* `iek` Input value e(k)

Generated by [Moxygen](https://sourcey.com/moxygen)
