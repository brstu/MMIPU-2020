# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Lin`](#class_lin) | Class for linear solving.
`class `[`Model`](#class_model) | Inheritance class.
`class `[`Non_lin`](#class_non__lin) | Class for non-linear solving.
`class `[`Regulate`](#class_regulate) | Regulaton class.

# class `Lin` 

```
class Lin
  : public Model
```  

Class for linear solving.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`a`](#class_lin_1adeff05a17bf6f1ae8a3e8a24b20cda13) | 
`public float `[`b`](#class_lin_1a151bfb50f8e538b5657c0c2ee34eb849) | 
`public virtual float `[`calc`](#class_lin_1a0c9249f6d86837caa758c271c2b3d522)`(float u_t,float y_t)` | [Lin](#class_lin) class method.

## Members

#### `public float `[`a`](#class_lin_1adeff05a17bf6f1ae8a3e8a24b20cda13) 

#### `public float `[`b`](#class_lin_1a151bfb50f8e538b5657c0c2ee34eb849) 

#### `public virtual float `[`calc`](#class_lin_1a0c9249f6d86837caa758c271c2b3d522)`(float u_t,float y_t)` 

[Lin](#class_lin) class method.

# class `Model` 

Inheritance class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`calc`](#class_model_1ac5cef11daca77dd2b9208af0d54f951b)`(float u_t,float y_t)` | 

## Members

#### `public float `[`calc`](#class_model_1ac5cef11daca77dd2b9208af0d54f951b)`(float u_t,float y_t)` 

# class `Non_lin` 

```
class Non_lin
  : public Model
```  

Class for non-linear solving.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`a`](#class_non__lin_1afcc424e21e394e0f977c899b9aee1fd7) | 
`public float `[`b`](#class_non__lin_1aa605085cdf79e6afe170b85b962c6efa) | 
`public float `[`c`](#class_non__lin_1ad9d2c255a4d6ffa5bc24c1e7b7ac7d75) | 
`public float `[`d`](#class_non__lin_1ad40ca37a5816b5f5ce8e5868c5b0178f) | 
`public float `[`u_t0`](#class_non__lin_1a055d756334d8b929384342369d3838ce) | 
`public float `[`y_t0`](#class_non__lin_1ab250132b8b40da40d0c5039f3b2d5e8d) | 
`public virtual float `[`calc`](#class_non__lin_1a38d9eca8a1d1c8d5a1a47dc47a2eb416)`(float u_t,float y_t)` | Non-lin class method.

## Members

#### `public float `[`a`](#class_non__lin_1afcc424e21e394e0f977c899b9aee1fd7) 

#### `public float `[`b`](#class_non__lin_1aa605085cdf79e6afe170b85b962c6efa) 

#### `public float `[`c`](#class_non__lin_1ad9d2c255a4d6ffa5bc24c1e7b7ac7d75) 

#### `public float `[`d`](#class_non__lin_1ad40ca37a5816b5f5ce8e5868c5b0178f) 

#### `public float `[`u_t0`](#class_non__lin_1a055d756334d8b929384342369d3838ce) 

#### `public float `[`y_t0`](#class_non__lin_1ab250132b8b40da40d0c5039f3b2d5e8d) 

#### `public virtual float `[`calc`](#class_non__lin_1a38d9eca8a1d1c8d5a1a47dc47a2eb416)`(float u_t,float y_t)` 

Non-lin class method.

# class `Regulate` 

Regulaton class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`K`](#class_regulate_1ae9ff945e5f7026bbb0faf5890704d9f4) | 
`public float `[`T`](#class_regulate_1ac9059319cd009bba3312d10a79498a95) | 
`public float `[`TD`](#class_regulate_1a6518b7f1dd1efe3828609f0e1da1cc21) | 
`public float `[`T0`](#class_regulate_1a0b227e8d0307454880ae181e67502dc0) | 
`public float `[`u_t`](#class_regulate_1a50e20933d7f3a59150173f843eaa2054) | 
`public float `[`get_U_t`](#class_regulate_1ad22303999e2e3ffa24e1cb3c3b90609d)`(float e,float e_0,float e_00)` | [Regulate](#class_regulate) class methods.
`public void `[`start_PID`](#class_regulate_1a0b7b4492b4de1b3e62d7d0cc877c4262)`(float w,`[`Model`](#class_model)` * model,float y_t)` | 

## Members

#### `public float `[`K`](#class_regulate_1ae9ff945e5f7026bbb0faf5890704d9f4) 

#### `public float `[`T`](#class_regulate_1ac9059319cd009bba3312d10a79498a95) 

#### `public float `[`TD`](#class_regulate_1a6518b7f1dd1efe3828609f0e1da1cc21) 

#### `public float `[`T0`](#class_regulate_1a0b227e8d0307454880ae181e67502dc0) 

#### `public float `[`u_t`](#class_regulate_1a50e20933d7f3a59150173f843eaa2054) 

#### `public float `[`get_U_t`](#class_regulate_1ad22303999e2e3ffa24e1cb3c3b90609d)`(float e,float e_0,float e_00)` 

[Regulate](#class_regulate) class methods.

#### `public void `[`start_PID`](#class_regulate_1a0b7b4492b4de1b3e62d7d0cc877c4262)`(float w,`[`Model`](#class_model)` * model,float y_t)` 

Generated by [Moxygen](https://sourcey.com/moxygen)