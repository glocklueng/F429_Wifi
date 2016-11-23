#ifndef __COMMON_H__
#define __COMMON_H__	 
#include "sys.h"
#include "usart.h"		
#include "delay.h"	 
#include "malloc.h"
#include "string.h"    

void atk_8266_at_response(u8 mode);                  // ���յ���ATָ��Ӧ�����ݷ��ظ����Դ���
u8* atk_8266_check_cmd(u8 *str);                     // ATK-ESP8266���������,�����յ���Ӧ��
u8 atk_8266_send_data(u8 *data,u8 *ack,u16 waittime);// ��ATK-ESP8266����ָ������
u8 atk_8266_send_cmd(u8 *cmd,u8 *ack,u16 waittime);  // ��ATK-ESP8266��������
u8 atk_8266_quit_trans(void);                        // ATK-ESP8266�˳�͸��ģʽ
u8 atk_8266_consta_check(void);                      // ��ȡATK-ESP8266ģ�������״̬   ����ֵ:0,δ����;1,���ӳɹ�.
void atk_8266_get_wanip(u8* ipbuf);                  // ��ȡClient ip��ַ   ��wifiģ���IP
void atk_8266_wificonf_show(u16 x,u16 y,u8* rmd,u8* ssid,u8* encryption,u8* password);


//�û����ò���
extern const u8* remote_ip;	         // Զ�̷�����IP
extern const u8* portnum;			       // ���Ӷ˿�
 
extern const u8* wifista_ssid;		   // WIFI STA SSID
extern const u8* wifista_encryption; // WIFI STA ���ܷ�ʽ
extern const u8* wifista_password; 	 // WIFI STA ����

extern const u8* wifiap_ssid;		     // WIFI AP SSID
extern const u8* wifiap_encryption;	 // WIFI AP ���ܷ�ʽ
extern const u8* wifiap_password; 	 // WIFI AP ����

// �û��ӿ�API
void atk_8266_init(void);                 // ATK-ESP8266ģ���ʼ�����ú���
u8 atk_8266_wifisend_data(u8 *Wifi_Data); // wifiģ�鷢������  TCP Client
#endif





