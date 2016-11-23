#ifndef __COMMON_H__
#define __COMMON_H__	 
#include "sys.h"
#include "usart.h"		
#include "delay.h"	 
#include "malloc.h"
#include "string.h"    

void atk_8266_at_response(u8 mode);                  // 将收到的AT指令应答数据返回给电脑串口
u8* atk_8266_check_cmd(u8 *str);                     // ATK-ESP8266发送命令后,检测接收到的应答
u8 atk_8266_send_data(u8 *data,u8 *ack,u16 waittime);// 向ATK-ESP8266发送指定数据
u8 atk_8266_send_cmd(u8 *cmd,u8 *ack,u16 waittime);  // 向ATK-ESP8266发送命令
u8 atk_8266_quit_trans(void);                        // ATK-ESP8266退出透传模式
u8 atk_8266_consta_check(void);                      // 获取ATK-ESP8266模块的连接状态   返回值:0,未连接;1,连接成功.
void atk_8266_get_wanip(u8* ipbuf);                  // 获取Client ip地址   即wifi模块的IP
void atk_8266_wificonf_show(u16 x,u16 y,u8* rmd,u8* ssid,u8* encryption,u8* password);


//用户配置参数
extern const u8* remote_ip;	         // 远程服务器IP
extern const u8* portnum;			       // 连接端口
 
extern const u8* wifista_ssid;		   // WIFI STA SSID
extern const u8* wifista_encryption; // WIFI STA 加密方式
extern const u8* wifista_password; 	 // WIFI STA 密码

extern const u8* wifiap_ssid;		     // WIFI AP SSID
extern const u8* wifiap_encryption;	 // WIFI AP 加密方式
extern const u8* wifiap_password; 	 // WIFI AP 密码

// 用户接口API
void atk_8266_init(void);                 // ATK-ESP8266模块初始化配置函数
u8 atk_8266_wifisend_data(u8 *Wifi_Data); // wifi模块发送数据  TCP Client
#endif





