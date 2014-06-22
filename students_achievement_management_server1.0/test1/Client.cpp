#include <stdio.h>      
#include <sys/socket.h> 
#include <arpa/inet.h>  
#include <stdlib.h>
#include <iostream> 
#include <string.h>   
#include <string.h>
#include <unistd.h>     
using namespace std;
#define RCVBUFSIZE 2048
#define size 100

void DieWithError(const char *errorMessage);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in echoServAddr; 
    unsigned short echoServPort; 
    char *servIP;  
    char *echoString;  
    char echoBuffer[RCVBUFSIZE]; 
    unsigned int echoStringLen;  
    int bytesRcvd, totalBytesRcvd;
    unsigned char len;
	int flag;

    char cm1[size]="student_login";
    char cm2[size]="student_select_course";
    char cm3[size]="student_delete_course";
    char cm4[size]="student_view_course";
    char cm5[size]="student_view_score";

    char cm6[size]="teacher_login";
    char cm7[size]="teacher_arrage_homework";
    char cm8[size]="teacher_set_point";
    char cm9[size]="teacher_view_course";

    char cm10[size]="admin_login";
    char cm11[size]="admin_add_course";
    char cm12[size]="admin_delete_course";
    char cm13[size]="admin_change_course";
    char cm14[size]="admin_view_course";
    char cm15[size]="admin_add_teacher";
    char cm16[size]="admin_delete_teacher";
    char cm17[size]="admin_add_student";
    char cm18[size]="admin_delete_teacher";

	char cm19[size]="logout";
	
	char cm20[size]="register_account";
	char cm21[size]="change_mail_addr";
	char cm22[size]="change_passwd";
	char cm23[size]="add_user_info";
	char cm24[size]="delete_user_info";

    if ((argc < 2) || (argc > 3)) 
    {
        fprintf(stderr, "Usage: %s <Server IP> [<Echo Port>]\n",
            argv[0]);
        exit(1);
    }

    servIP = argv[1];

    if (argc == 3)
        echoServPort = atoi(argv[2]); 
    else
        echoServPort = 8888; 

    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    memset(&echoServAddr, 0, sizeof(echoServAddr)); 
    echoServAddr.sin_family      = AF_INET;           
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);   
    echoServAddr.sin_port        = htons(echoServPort); 


    if (connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
        DieWithError("connect() failed");

	for(;;)
	{
    	int state=0;
    	char a[size]={0};
    	int b=0;
    	char c[size]={0};
    	printf("登录(student_login for student; \
				teacher_login for teacher; admin_login for administrator;register_account for RegisterAccount)\n");
    	scanf("%s", a);

    	if(strncmp(cm1, a, size)==0)
        	state = 1;
    	else if(strncmp(cm6, a, size) ==0)
        	state = 6;
    	else if(strncmp(cm10, a, size) ==0)
        	state = 10;
    	else if(strncmp(cm20, a, size) ==0)
        	state = 20;

    
    	switch(state)
    	{
        	case 1:
            	printf("输入帐号密码:");
            	scanf("%d %s", &b, c);
            	
				memset(echoBuffer, 0, RCVBUFSIZE);
				
				printf("%d\n", b);

            	echoBuffer[1]=1;
            	echoBuffer[2]=0;						
           		memcpy(echoBuffer+3, &b, 4);
          		memcpy(echoBuffer+7, c, size);
          		
       //   		printf("%s\n", echoBuffer+3);
       //   		printf("%s\n", echoBuffer+7);

				if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			DieWithError("send() sent a different number of bytes than expected");

				memset(echoBuffer, 0, RCVBUFSIZE);

				if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			DieWithError("recive() failed or connection closed prematurely");
        			

				if(echoBuffer[0]==1)
				{
			    	printf("登录成功\n");
					flag = 1;
			    	while(flag)
			    	{
    					printf("学生选择操作命令\n");					
			        	scanf("%s",a);

			        	if (strncmp(cm2, a,sizeof(a)) ==0)
			        	{
			        	  
			            	state = 2;
			            }
			        	else if (strncmp(cm3, a,sizeof(a)) ==0)
			        	{
			        	  
			            	state = 3;
			            }
			        	else if (strncmp(cm4, a,sizeof(a)) ==0)
			        	{
			        	    
                        	state = 4;
                        }
                    	else if (strncmp(cm5, a,sizeof(a)) ==0)
                    	{
                    	    printf("===5==\n");
                        	state = 5;
                        }
                    	else if (strncmp(cm19, a,sizeof(a)) ==0)
                    	{
                        	state = 19;
                        }
                    	else if (strncmp(cm21, a,sizeof(a)) ==0)
                    	{
                        	state = 21;
                        }
                    	else if (strncmp(cm22, a,sizeof(a)) ==0)
                    	{
                        	state = 22;
                        }
                        else
                        {
                            state = 100;
                        }
                    
                    	switch (state)
                    	{
                        	case 2: //student_select_course
                        	{

    							printf("选择添加课程号\n");
			        			scanf("%d",&b);
								memset(echoBuffer, 0, RCVBUFSIZE);
				            	echoBuffer[1]=1;	
				            	echoBuffer[2]=1;			

           						memcpy(echoBuffer+3, &b, sizeof(b));
           						

                            	if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	DieWithError("send() sent a different number of bytes than expected");

								memset(echoBuffer, 0, RCVBUFSIZE);

                            	if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	DieWithError("recive() failed or connection closed prematurely");
        			
        	                	if(echoBuffer[0]==0)
					            	printf("选课成功\n");
				            	else 
					            	printf("选课失败\n");
			            	break;
			            	}

			            	case 3: //student_delete_course
			            	{
    							printf("选择删除课程号\n");
			        			scanf("%d",&b);

								memset(echoBuffer, 0, RCVBUFSIZE);			
				            	echoBuffer[1]=1;	
				            	echoBuffer[2]=2;	

           						memcpy(echoBuffer+3, &b, sizeof(b));
			
                            	if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	DieWithError("send() sent a different number of bytes than expected");

								memset(echoBuffer, 0, RCVBUFSIZE);

                            	if (recv(sock, echoBuffer, RCVBUFSIZE , 0)!= RCVBUFSIZE)
        			            	DieWithError("recive() failed or connection closed prematurely");
        			
        	                	if(echoBuffer[0]==0)
					            	printf("删课成功\n");
				            	else 
					            	printf("删课失败\n");

			            	break;
			            	}
			            
			            	case 4: //学生查课程
			                {
			
				            	echoBuffer[1]=1;	
				            	echoBuffer[2]=3;	

                            	if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	DieWithError("send() sent a different number of bytes than expected");

								memset(echoBuffer, 0, RCVBUFSIZE);

                            	if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	DieWithError("recive() failed or connection closed prematurely");
        			
        	                	if(echoBuffer[0]==1)
        	                	{
					            	printf("查看课程失败\n");
				            	}
				            	else
				            	{
				            	    printf("所选课程信息\n");
				            	    int row, column;
				            	    row = echoBuffer[1];
				            	    column = echoBuffer[2];
				            	    printf("%d  %d\n", row, column);
				            	    for(int i=0; i<row; i++)
				            	    {
				            	        for(int j=0; j<column; j++)
				            	        {
				            	            if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	            DieWithError("recive() failed or connection closed prematurely");
        			            	        printf("%s    ", echoBuffer);
				            	        }
				            	        printf("\n");
					            	}
					            }	


			            	break;
			            	}
			            
			            	case 5: //学生查分数
			            	{
				            			
				            	echoBuffer[1]=1;	
				            	echoBuffer[2]=4;	
			
                            	if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	DieWithError("send() sent a different number of bytes than expected");

								memset(echoBuffer, 0, RCVBUFSIZE);

                            	if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	DieWithError("recive() failed or connection closed prematurely");
        			
        	                	if(echoBuffer[0]==0)
					            	printf("查看成绩失败\n");
				            	else
				            	{
				            	    printf("===view score====\n");
				            	    int row, column;
				            	    row = echoBuffer[1];
				            	    column = echoBuffer[2];
				            	    for(int i=0; i<row; i++)
				            	    {
				            	        for(int j=0; j<column; j++)
				            	        {
				            	            if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	            DieWithError("recive() failed or connection closed prematurely");
        			            	        printf("%s    ", echoBuffer);
				            	        }
				            	        printf("\n");
					            	}
					            }	

			            	break;
			            	}

			            	case 19: //logout
				            {
			
				            	echoBuffer[1]=1;	
				            	echoBuffer[2]=5;	
								flag = 0;
                            	if (send(sock, echoBuffer, len, 0) != len)
        			            	DieWithError("send() sent a different number of bytes than expected");
        			            	
        			            exit(0);


			            	break;
							case 21://更换邮箱地址
				            	echoBuffer[1]=1;	
				            	echoBuffer[2]=6;
								
								printf("输入新邮箱\n");
            					scanf("%s", c);

								memcpy(&echoBuffer[3], c, size);

                            	if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	DieWithError("send() sent a different number of bytes than expected");

								memset(echoBuffer, 0, RCVBUFSIZE);

                            	if (recv(sock, echoBuffer, RCVBUFSIZE , 0)!= RCVBUFSIZE)
        			            	DieWithError("recive() failed or connection closed prematurely");
        			
        	                	if(echoBuffer[0]==0)
					            	printf("更换邮箱成功\n");
				            	else 
					            	printf("更换邮箱失败\n");								
							break;
							}

							case 22://更换密码
							{
				            	echoBuffer[1]=1;	
				            	echoBuffer[2]=7;
								
								printf("输入新密码\n");
            					scanf("%s", c);

								memcpy(&echoBuffer[3], c, size);

                            	if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	DieWithError("send() sent a different number of bytes than expected");

								memset(echoBuffer, 0, RCVBUFSIZE);

                            	if (recv(sock, echoBuffer, RCVBUFSIZE , 0)!= RCVBUFSIZE)
        			            	DieWithError("recive() failed or connection closed prematurely");
        			
        	                	if(echoBuffer[0]==0)
					            	printf("更换密码成功\n");
				            	else 
					            	printf("更换密码失败\n");								
							break;
							}
							
						    case 100:
						    {
						        printf("没有此命令\n");
							break;
						    }	
                    	}//switch
			        			    
			    	}//while
				}//if
            	else 
			    	printf("登录失败，请检查\n");
			break;
		
			case 6://老师登录
		    	printf("输入帐号密码:");
            	scanf("%d %s", &b, c);

				memset(echoBuffer, 0, RCVBUFSIZE); 
         
            	echoBuffer[1]=2;
            	echoBuffer[2]=0;						

          		memcpy(echoBuffer+3, &b, 4);
          		memcpy(echoBuffer+7, c, size);

				if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			DieWithError("send() sent a different number of bytes than expected");

				memset(echoBuffer, 0, RCVBUFSIZE);

				if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			DieWithError("recive() failed or connection closed prematurely");


				if(echoBuffer[0]==1)
				{
			    	printf("登录成功\n");
					flag = 1;

					while(flag)
					{
    					printf("老师选择操作命令\n");
			    		scanf("%s",a);

			    		if (strncmp(cm6, a,sizeof(a)) ==0)
			    			state = 6;
			    		else if (strncmp(cm7, a,sizeof(a)) ==0)
			    			state = 7;
			   	 		else if (strncmp(cm4, a,sizeof(a)) ==0)
                			state = 8;
                		else if (strncmp(cm5, a,sizeof(a)) ==0)
                			state = 9;
                		else if (strncmp(cm19, a,sizeof(a)) ==0)
                			state = 19;
                    	else if (strncmp(cm21, a,sizeof(a)) ==0)
                        	state = 21;
                    	else if (strncmp(cm22, a,sizeof(a)) ==0)
                        	state = 22;
                        cout << state << endl;
                		switch (state)
                		{
 							case 7://老师布置作业
							printf("输入作业名字 时间 和班级号\n");

		    				char name[size];
		    				char time[size];
		    				int cid;

            				scanf("%s %s %d", name, time,&cid);	

							memset(echoBuffer, 0, RCVBUFSIZE); 	    
		    				memcpy(echoBuffer+3, name, size);
		    				memcpy(echoBuffer+size+3, time, size);
		    				memcpy(echoBuffer+(2*size)+3, &cid, sizeof(cid));
			
							echoBuffer[1]=2;	
							echoBuffer[2]=1;	

							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");

        	                if(echoBuffer[0]==0)
					            printf("布置作业成功\n");
				            else 
					            printf("布置作业失败\n");

							break;

							case 8://老师打分
		    				int sid;
		    				int hid;
		    				int score;

            				scanf("%d %d %d", &sid, &hid,&score);

							memset(echoBuffer, 0, RCVBUFSIZE); 	    
		    				memcpy(echoBuffer+3, &sid, 4);
		    				memcpy(echoBuffer+7, &hid, 4);
		    				memcpy(echoBuffer+11, &score, 4);	
			
							echoBuffer[1]=2;	
							echoBuffer[2]=2;	


							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");

        	                if(echoBuffer[0]==0)
					            printf("打分成功\n");
				            else 
					            printf("打分失败\n");
						break;

						case 9://老师查看课程
    						printf("选择查看班级\n");
			        		scanf("%d", &b);

           					memcpy(echoBuffer+3, &b, sizeof(b));
			
							echoBuffer[1]=2;	
							echoBuffer[2]=3;	

							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");

        	                if(echoBuffer[0]==0)
					            printf("查看课程失败\n");
				            else 
				            {
				            	int row, column;
				            	row = echoBuffer[1];
				            	column = echoBuffer[2];
				            	for(int i=0; i<row; i++)
				            	{
				            	    for(int j=0; j<column; j++)
				            	    {
				            	        if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            	        DieWithError("recive() failed or connection closed prematurely");
        			            	    printf("%s    ", echoBuffer);
				            	    }
				            	    printf("\n");
					           	}
					        }	
						break;

						case 19://logout
			
							echoBuffer[1]=2;	
							echoBuffer[2]=4;
	
							flag = 0;
                            if (send(sock, echoBuffer, len, 0) != len)
        			            DieWithError("send() sent a different number of bytes than expected");
        			        exit(0);

						break;
						case 21://更换邮箱地址
				            echoBuffer[1]=2;	
				            echoBuffer[2]=5;
								
							printf("输入新邮箱\n");
            				scanf("%s", c);

							memcpy(&echoBuffer[3], c, size);

                            if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

                            if (recv(sock, echoBuffer, RCVBUFSIZE , 0)!= RCVBUFSIZE)
        			            DieWithError("recive() failed or connection closed prematurely");
        			
        	                if(echoBuffer[0]==0)
					            printf("更换邮箱成功\n");
				            else 
					            printf("更换邮箱失败\n");								
						break;

						case 22://更换密码
				            echoBuffer[1]=2;	
				            echoBuffer[2]=6;
								
							printf("输入新密码\n");
            				scanf("%s", c);

							memcpy(&echoBuffer[3], c, size);

                            if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			            DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

                            if (recv(sock, echoBuffer, RCVBUFSIZE , 0)!= RCVBUFSIZE)
        			            DieWithError("recive() failed or connection closed prematurely");
        			
        	                if(echoBuffer[0]==0)
					            printf("更换邮箱成功\n");
				            else 
					            printf("更换邮箱失败\n");								
							break;
		    
			    		}//switch
					}//while
				}//if
            	else 
			    	printf("登录失败，请检查\n");
			break;
		
			case 10://admin
		    	printf("输入帐号密码:");
            	scanf("%d %s", &b, c);

				memset(echoBuffer, 0, RCVBUFSIZE); 
         
            	echoBuffer[1]=3;
            	echoBuffer[2]=0;						
           		memcpy(echoBuffer+3, &b, 4);
          		memcpy(echoBuffer+7, c, size);

				if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			DieWithError("send() sent a different number of bytes than expected");

				memset(echoBuffer, 0, RCVBUFSIZE);

				if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			DieWithError("recive() failed or connection closed prematurely");

				if(echoBuffer[0]==1)
				{
			    	printf("登录成功\n");
					int flag;
					flag = 1;
			    	while(flag)
					{
    					printf("教务处管理员选择操作命令\n");
			    		scanf("%s",a);

			    		if (strncmp(cm11, a,size) ==0)
			    			state = 11;
			    		else if (strncmp(cm12, a,size) ==0)
			    			state = 12;
			   	 		else if (strncmp(cm13, a,size) ==0)
                			state = 13;
/*                		else if (strncmp(cm14, a,size) ==0)
                			state = 14;*/
                		else if (strncmp(cm15, a,size) ==0)
                			state = 15;				
               			else if (strncmp(cm16, a,size) ==0)
                			state = 16;
                		else if (strncmp(cm17, a,size) ==0)
                			state = 17;
                		else if (strncmp(cm18, a,size) ==0)
                			state = 18;
                		else if (strncmp(cm19, a,size) ==0)
                			state = 19;

                    	else if (strncmp(cm23, a,size) ==0)
                        	state = 23;
                    	else if (strncmp(cm24, a,size) ==0)
                        	state = 24;

                        switch(state)
                        {
						case 11://添加课程
                        {
    						printf("输入添加课程班级号 名称 学分 学时 老师ID 课程类型\n");
		    				int cid;
		    				char name[size];
		    				int credit;
		    				int course_hours;
		    				int tid;
		    				char course_type[size];

            				scanf("%d %s %d %d %d %s", &cid, name, &credit,
                                    &course_hours, &tid, course_type);

							memset(echoBuffer, 0, RCVBUFSIZE); 	    
		    				memcpy(echoBuffer+3, &cid, 4);
		    				memcpy(echoBuffer+7, name, size);
		    				memcpy(echoBuffer+7+size, &credit, 4);
		    				memcpy(echoBuffer+11+size, &course_hours, 4);
		    				memcpy(echoBuffer+15+size, &tid, 4);
		    				memcpy(echoBuffer+19+size, course_type, size);

							echoBuffer[1]=3;	
							echoBuffer[2]=1;	

							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");

        	                if(echoBuffer[0]==0)
					            printf("添加课程成功\n");
				            else 
					            printf("添加课程失败\n");
						break;
                        }					

						case 12://管理员删除课程
			            {
    							printf("输入删除课程号\n");
			        			scanf("%d", &b);

								memset(echoBuffer, 0, RCVBUFSIZE);			
				            	echoBuffer[1]=3;	
				            	echoBuffer[2]=2;	

           						memcpy(echoBuffer+3, &b, sizeof(b));
	
								if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        							DieWithError("send() sent a different number of bytes than expected");

								memset(echoBuffer, 0, RCVBUFSIZE);

								if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        							DieWithError("recive() failed or connection closed prematurely");

        	                	if(echoBuffer[0]==0)
					            	printf("删除课程成功\n");
				            	else 
					            	printf("删除课程失败\n");
								
						break;
                        }
						case 13://更改已有课程
                        {
    						printf("输入添加课程班级号 名称 学分 学时 老师ID 课程类型\n");
		    				int cid;
		    				char name[size];
		    				int credit;
		    				int course_hours;
		    				int tid;
		    				char course_type[size];

            				scanf("%d %s %d %d %d %s", &cid, name,&credit, &course_hours, &tid, course_type);

							memset(echoBuffer, 0, RCVBUFSIZE); 	    
		    				memcpy(echoBuffer+3, &cid, 4);
		    				memcpy(echoBuffer+7, name, size);
		    				memcpy(echoBuffer+7+size, &credit, 4);
		    				memcpy(echoBuffer+11+size, &course_hours, 4);
		    				memcpy(echoBuffer+15+size, &tid, 4);
		    				memcpy(echoBuffer+19+size, course_type, size);
			
							echoBuffer[1]=3;	
							echoBuffer[2]=3;	
	
							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");

        	                if(echoBuffer[0]==0)
					            printf("更改课程成功\n");
				            else 
					            printf("更改课程失败\n");
								
						break;
                        }
/*					case 14://admin_view_course

						//unsigned char len
						len = 
						echoBuffer[0] = len;			
						echoBuffer[1]=3;	
						echoBuffer[2]=4;	


		    			if (send(sock, echoBuffer, echoStringLen, 0) != echoStringLen)
        					DieWithError("send() sent a different number of bytes than expected");

						if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0)
            				DieWithError("recv() failed or connection closed prematurely");
								
					break;
*/
						case 15://添加老师
                        {
    						printf("输入添加老师教师号 名字 性别 电话 职称 学院 生日\n");
		    				int tid;
		    				char name[size];
		    				char teach_sex[size];
		    				char phone[size];
		    				char tittle[size];
		    				char department[size];
		    				char birth[size];
            				scanf("%d %s %s %s %s %s %s", &tid, name,teach_sex, phone, tittle, department, birth);

							memset(echoBuffer, 0, RCVBUFSIZE); 	    
		    				memcpy(echoBuffer+3, &tid, 4);
		    				memcpy(echoBuffer+7, name, size);
		    				memcpy(echoBuffer+7+size, teach_sex, size);
		    				memcpy(echoBuffer+7+2*size, phone, size);
		    				memcpy(echoBuffer+7+3*size, tittle, size);
		    				memcpy(echoBuffer+7+4*size, department, size);
		    				memcpy(echoBuffer+7+5*size, birth, size);
			
							echoBuffer[1]=3;	
							echoBuffer[2]=5;	
							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");

        	                if(echoBuffer[0]==0)
					            printf("添加老师成功\n");
				            else 
					            printf("添加老师失败\n");//
								
						break;
                        }
						case 16://删除老师
                        {
    						printf("选择删除老师号\n");
			        		scanf("%d", &b);

							memset(echoBuffer, 0, RCVBUFSIZE);			
				            echoBuffer[1]=3;	
				            echoBuffer[2]=6;	

           					memcpy(echoBuffer+3, &b, sizeof(b));

							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");

        	                if(echoBuffer[0]==0)
					            printf("删除老师成功\n");
				            else 
					            printf("删除老师失败\n");
								
						break;
                        }

						case 17://增加学生
                        {
    						printf("输入添加学生学生号 名字 性别 班级 生日\n");
            				int sid;
            				char name[size];
            				char sex[size];
            				char classid[size];
            				char birth[size];

            				scanf("%d %s %s %s %s ", &sid, name,sex, classid, birth);

							memset(echoBuffer, 0, RCVBUFSIZE); 	    
		    				memcpy(echoBuffer+3, &sid, 4);
		    				memcpy(echoBuffer+7, name, size);
		    				memcpy(echoBuffer+7+size, sex, size);
                            memcpy(echoBuffer+7+2*size, classid, size);
		    				memcpy(echoBuffer+7+3*size, birth, size);

							echoBuffer[1]=3;	
							echoBuffer[2]=7;	

							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");//参数未添加

        	                if(echoBuffer[0]==0)
					            printf("增加学生成功\n");
				            else 
					            printf("删除学生失败\n");//
								
							break;
                        }

						case 18://删除学生
                        {
    						printf("选择删除学生号\n");
			        		scanf("%d", &b);

							memset(echoBuffer, 0, RCVBUFSIZE);			
				            echoBuffer[1]=3;	
				            echoBuffer[2]=6;	

           					memcpy(echoBuffer+3, &b, sizeof(b));

							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");
								
						break;
                        }

						case 19://logout
			            {
							echoBuffer[1]=3;	
							echoBuffer[2]=9;	


		    				if (send(sock, echoBuffer, echoStringLen, 0) != echoStringLen)
        						DieWithError("send() sent a different number of bytes than expected");

							if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0)
            					DieWithError("recv() failed or connection closed prematurely");
            					
            			    exit(0);
								
						break;
                        }

						case 23://增加可注册人ID
                        {
							echoBuffer[1]=3;	
							echoBuffer[2]=10;	

			    			scanf("%d ",&b);	
							memcpy(&echoBuffer[3], &b, sizeof(b));

							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");//参数未添加

        	                if(echoBuffer[0]==0)
					            printf("增加成功\n");
				            else 
					            printf("增加失败\n");//
								
							break;
                        }
		
						case 24://删除可注册人ID
                        {
							echoBuffer[1]=3;	
							echoBuffer[2]=11;	

			    			scanf("%d ",&b);	
							memcpy(&echoBuffer[3], &b, sizeof(b));

							if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("send() sent a different number of bytes than expected");

							memset(echoBuffer, 0, RCVBUFSIZE);

							if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        						DieWithError("recive() failed or connection closed prematurely");//参数未添加

        	                if(echoBuffer[0]==0)
					            printf("删除成功\n");
				            else 
					            printf("删除失败\n");//未完成，参数未设定
								
							break;
                        }
                        }
					}
				
				}
            	else 
			    	printf("login failed ,check out\n");
			break;

			case 20:
				
				char d[size];
				int e;

                memset(d, 0, size);
                e = 0;			
				
				printf("输入ID 邮箱 密码 权限（管理员 选1 老师选2 学生选3）\n");
			    scanf("%d %s %s %d",&b,c,d,&e);				
				echoBuffer[1]=4;	
				echoBuffer[2]=0;

           		memcpy(echoBuffer+3, &b, sizeof(b));
           		memcpy(echoBuffer+3+sizeof(b), c, sizeof(c));
           		memcpy(echoBuffer+3+sizeof(b)+sizeof(c), d, sizeof(d));
           		memcpy(echoBuffer+3+sizeof(b)+sizeof(c)+sizeof(d), &d, sizeof(d));				

				if (send(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			DieWithError("send() sent a different number of bytes than expected");

				memset(echoBuffer, 0, RCVBUFSIZE);

				if (recv(sock, echoBuffer, RCVBUFSIZE, 0) != RCVBUFSIZE)
        			DieWithError("recive() failed or connection closed prematurely");//参数未添加

        	    if(echoBuffer[0]==0)
					printf("注册成功\n");
				else 
					printf("注册失败\n");

			break;

			default:
			    break;
		
    	}//switch

	}//for(;;)
    close(sock);
    exit(0);        
}


