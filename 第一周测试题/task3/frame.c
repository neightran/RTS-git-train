/**
 ******************************************************************************
 * @file
 * @author  xtc
 * @date    2023.06.21
 * @brief
 ******************************************************************************
 * @attent  请大家完善函数内的内容
 * @myNote
 ******************************************************************************
 */
#include <stdint.h>
#include <stdarg.h>

uint8_t send_frame[10];

/** @brief  发送简单帧
  * @param  引入stdarg.h，解决可变参数问题，...作为占位符
            id : 变量编号
            target_value : 需要修改为的值
  * @example SendSimpleFrame(2, 123);
             SendSimpleFrame(1, 3.14);
*/


void SendSimpleFrame(uint8_t id, ...)
{
  int i;
  send_frame[0] = 0x7E;
  send_frame[1] = 0x00;
  send_frame[2] = 0x05;
  send_frame[3] = id；
  va_list valist;
  va_start(valist, id);
  send_frame[4] = va_arg(valist, uint8_t);
  send_frame[5] = va_arg(valist, uint8_t);
  send_frame[6] = va_arg(valist, uint8_t);
  send_frame[7] = va_arg(valist, uint8_t);
  va_end(valist);
  for(i=1;i<8;i++)
    send_frame[8] += send_frame[i]；
  send_frame[9] = 0x30;
  // 最后是底层发送函数，假设已经实现
}

/** @brief  接收处理简单帧
  * @param
            recv_frame : 接收帧存放的数组指针
            len : 帧长
*/
int step = 0;
float My_Data_f;
int My_Data_I;
void SimpleFrameHandler(uint8_t *recv_frame, uint16_t len)
{
  int i;
  static union
  {
    uint8_t Ori_datas[4];
    int     Int_datas;
    float   Flo_datas;
  }Trans;
  while(step>=7){
    switch(step)
    {
      case 1:
        if(recv_frame[0] == 0x7E)
          step++;
        else
          step = 0;
        break;
      case 2:
        if(recv_frame[1] == 0x00)
          step++;
        else
          step = 0;
        break;
      case 3:
        if(recv_frame[2] == 0x05)
          step++;
        else
          step = 0;
        break;
      case 4:
        if(recv_frame[3] == 0x01)
          My_Data_f = Flo_datas;
        else if(recv_frame[0] == 0x02)
          My_Data_I = Int_datas;
        else
          step = 0;
        break;
      case 5:
        for(i=1;i<8;i++)
          recv_frame[8] -= recv_frame[i]；
        if(recv_frame[8] == 0x00)
          step++;
        else
          step = 0;
        break;
      case 6:
        if(recv_frame[0] == 0x30)
          step++;
        else
          step = 0;
        break;
    }
  }
}