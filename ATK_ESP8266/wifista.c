#include "common.h"
#include "stdlib.h"
#include "stdio.h"

// wifi模块发送数据  TCP Client
// 返回值：0--失败     1--成功
u8 atk_8266_wifisend_data(u8 *Wifi_Data)
{
	u8 i = 0;
	u8 res = 0;
	u8 constate = 0;	                  // 连接状态
	u8 *p = mymalloc(SRAMIN,32);			  // 申请32字节内存
	
	for(i = 0; i < 2; i++) constate = atk_8266_consta_check(); // 得到连接状态
	if(constate=='+')  
	{
		printf("连接成功 ");
		atk_8266_quit_trans();
		atk_8266_send_cmd("AT+CIPSEND","OK",20);  // 开始透传   
		
		sprintf((char*)p,"%s\r\n",Wifi_Data);         
		u3_printf("%s",p);                           // 发送数据
		printf("已发送：%s\r\n", p); 
		res = 1;
	}
	else  
	{
		printf("连接失败 "); 
		res = 0;
	}
	atk_8266_at_response(1);
	myfree(SRAMIN,p);		//释放内存 
	return res;		
} 




























