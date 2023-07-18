/**
 ******************************************************************************
 * @file    PID.c
 * @author  Maxsh
 * @date    2021.07.14
 * @brief   PID算法面向对象风格的C语言实现
 ******************************************************************************
 * @attent  请大家完善函数内的内容
 * @myNote
 ******************************************************************************
 */

#include "PID.h"

static void Calculate(PID_t *pid, float current_value, float target_value);

PID_t pid;

/** @brief  结构体格式初始化，为输入参数结构体中的函数指针变量赋值，并初始化一些属性
  * @param  pid            : 被操作的结构体，可理解为self
            p              : 给定的p
            i              : 给定的i
            d              : 给定的d
            integral_limit : 积分值上限
            max_output     : PID输出上限
*/
void PID_StructInit(PID_t *pid, float p, float i, float d, float integral_limit, float max_output)
{
  // 初始化相关变量
  pid->TargetValue = 0.0f;
  pid->CurrentValue = 0.0f;
  pid->Error = 0.0f;
  pid->LastError = 0.0f;
  pid->PValue = 0.0f;
  pid->IValue = 0.0f;
  pid->DValue = 0.0f;
  pid->output = 0.0f;
  // 设置PID参数
  pid->KP = p;
  pid->KI = i;
  pid->KD = d;
  pid->integral_limit = integral_limit;
  pid->max_output = max_output;
  // 调用函数指针
  pid->f_Calculate = Calculate;
}

/** @brief  私有函数，但可以结构体内函数指针的方式被外部调用。功能为计算一帧的pid
  * @param  pid          : 被操作的结构体，可理解为self
            current_value: 该帧的当前值
            target_value : 目标值
*/
static void Calculate(PID_t *pid, float current_value, float target_value)
{
  // 更新目标值和当前值
  pid->TargetValue = target_value;
  pid->CurrentValue = current_value;
  // 计算误差
  pid->Error = pid->TargetValue - pid->CurrentValue;
  // 计算比例项
  pid->PValue = pid->KP * pid->Error;
  // 计算积分项
  pid->IValue += pid->KI * pid->Error;
  // 抗积分饱和限制
  if (pid->IValue > pid->integral_limit)
    pid->IValue = pid->integral_limit;
  else if (pid->IValue < -pid->integral_limit)
    pid->IValue = -pid->integral_limit;
  // 计算微分项
  pid->DValue = pid->KD * (pid->Error - pid->LastError);
  // 保存上次误差
  pid->LastError = pid->Error;
  // 计算输出
  pid->output = pid->PValue + pid->IValue + pid->DValue;
  // 输出限制
  if (pid->output > pid->max_output)
    pid->output = pid->max_output;
  else if (pid->output < -pid->max_output)
    pid->output = -pid->max_output;
}
