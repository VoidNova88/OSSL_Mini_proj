#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#define TABLE_SIZE 1000

// Function: isproper_date()
// Input: date - integer type date
// Output: 1 - TRUE, 0 - FALSE
// - check if the input date is proper form. If not, print an error message and return 0(FALSE)
int isproper_date(int date){
	  int month = date/100, day = date%100;
	    int end_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		  if(month < 1 || month > 13) {
			      printf("\tYour input date is not in proper format. Date should formed like MMDD. (ex. June 2nd -> 0602)\n");
				      return 0;}
		    else{
				    if(day > end_days[month - 1]) {
						      printf("\tYour input date is not in proper format. Date should formed like MMDD. (ex. April 16th -> 0416)\n");
							        return 0;}
					    else return 1;
						  }
}


// Function: isproper_type()
// Input: type - char type task type
// Output: 1 - TRUE, 0 - FAULS
// - check if the input type is proper form. If not, print an error message and return 0(FALSE)
int isproper_type(char type){
	  if(type == 'l'|| type == 'z'|| type == 'a' || type == 'e') return 1;
	    else {
			    printf("\tYour input type has wrong alphabet. The input must be lower case l, z, a or e\n");
				    return 0;}
}


// Function: copy_task()
// Input: empty - expect to be filled with other Task; filled - Task which has context wish to be copied
// Output: none
// - All context of Task filled is copied to Task empty
void copy_task(Task *empty, Task *filled){
	  strcpy(empty->task_name, filled->task_name);
	    strcpy(empty->class_name, filled->class_name);
		  strcpy(empty->release_date, filled->release_date);
		    strcpy(empty->due_date, filled->due_date);
			  empty->task_type = filled->task_type;
			    return;
}


// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle, cur_pos = current position of Task array
// Output: none
// - print all task informations
void print_all_records(Task records[], int *cur_pos){
		// TODO: Modify this function as you need
		int i;
		  printf("\nPrinting all tables....\n\n");
		    
		    for(i = 0; i < *cur_pos; i++){
				    printf("task no: %d\ntask name: %s\nclass name: %s\nrelease date: %s\ndue date: %s\ntask type: %c\n\n", i+1, records[i].task_name, records[i].class_name, records[i].release_date, records[i].due_date, records[i].task_type);
					  }
			  printf("\n");
			    return;
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle, cur_pos = current position of Task array
// Output: none
// - get a user input and add them into record[]
void add_a_record(Task records[], int *cur_pos){

	  Task input;
	    char confirmed = 'n';

		  printf("Adding a new Task in table....\n");
		    
		    while(confirmed != 'y'){
				    printf("Write a task name: ");
					    fgets(input.task_name, 100, stdin);
						    input.task_name[strlen(input.task_name)-1] = '\0';
							    input.task_name[strlen(input.task_name)] = 0;

								    printf("Write a class name: ");
									    fgets(input.class_name, 100, stdin);
										    input.class_name[strlen(input.class_name)-1] = '\0';
											    input.class_name[strlen(input.class_name)] = 0;

												    do{
														      printf("Write a release date of this task formed as MMDD: ");
															        fgets(input.release_date, 5, stdin);
																	      getchar();
																		        input.release_date[strlen(input.release_date)] = '\0';
																				    }
													    while(isproper_date(atoi(input.release_date)) == 0);
													    
													    do{
															      printf("Write a due date of this task formed as MMDD: ");
																        fgets(input.due_date, 5, stdin);
																		      getchar();
																			        input.due_date[strlen(input.due_date)] = '\0';
																					    }
													    while(isproper_date(atoi(input.due_date)) == 0);
													    
													    do{
															      printf("Write a task type. \'l\' for LMS lecture, \'z\' for Zoom meeting, \'a\' for assignment, \'e\' for exam or quiz preparation: ");
																        scanf("%c", &input.task_type);
																		      getchar();
																			      }
													    while(isproper_type(input.task_type) == 0);

													    printf("\n+++++++++++++++++++++++++++++++++\n");
													    printf("task name: %s\nclass name: %s\nrelease date: %s\ndue date: %s\ntask type: %c\n", input.task_name, input.class_name, input.release_date, input.due_date, input.task_type);
														    printf("+++++++++++++++++++++++++++++++++\n");
															    printf("\nIs all these task infos correct? press y for confirm tesk infos. ");
																    scanf("%c", &confirmed);
																	    printf("\n");
																		    getchar();
																			  }
			  
			  
			  strcpy(records[*cur_pos].task_name, input.task_name);
			    strcpy(records[*cur_pos].class_name, input.class_name);
				  strcpy(records[*cur_pos].release_date, input.release_date);
				    strcpy(records[*cur_pos].due_date, input.due_date);
					  records[*cur_pos].task_type = input.task_type;

					    *cur_pos = *cur_pos + 1;
						  return;
}


// Function: create_record_from_file()
// Input: record - array of Records; this may contain empty elements in the middle ,cur_pos - current position of Task array; opening file - task_data_open.txt
// Output: none
// - read a text file and make Task array. This function will overrides all the context of Task array.
void create_record_from_file(Task records[], int *cur_pos){

	  FILE *fp = fopen("task_data_open.txt", "rt");
	    int ret;
		  if(fp == NULL) {
			      printf("Error with opening text file!!\n");
				      return;
					    }
		    
		    *cur_pos = 0;
			  printf("Creating Task data from file.....\n");
			    while(1){
					    ret = fscanf(fp, "task name: %s/class name: %s/release date: %s/due date: %s/task type: %c", records[*cur_pos].task_name, records[*cur_pos].class_name, records[*cur_pos].release_date, records[*cur_pos].due_date, &records[*cur_pos].task_type);
						    *cur_pos = *cur_pos + 1;
							    if(ret == EOF) break;
								  }
				  fclose(fp);
				    printf("Creating Task data is finished.\n");
					  return;
}


// Function: read_record_from_file()
// Input: record - array of Records; this may contain empty elements in the middle ,cur_pos - current position of Task array; input file
// Output: none
// - read a text file and make Task array. This function will appends file context to Task array
void read_record_from_file(Task records[], int *cur_pos){
	  char *filename;
	    printf("Enter a file name to open: ");
		  fgets(filename, 100, stdin);
		    FILE *fp = fopen(filename, "rt");
			  int ret;
			    if(fp == NULL) {
					    printf("Error with opening text file!!\n");
						    return;
							  }
				  
				  printf("Appending Task data from file.....\n");
				    while(1){
						    if(ret == EOF) break;
							    ret = fscanf(fp, "task name: %s/class name: %s/release date: %s/due date: %s/task type: %c", records[*cur_pos].task_name, records[*cur_pos].class_name, records[*cur_pos].release_date, records[*cur_pos].due_date, &records[*cur_pos].task_type);
								    *cur_pos = *cur_pos + 1;
									  }
					  fclose(fp);
					    printf("Appending Task data is finished.\n");
						  return;
}


// Function: make_txt_from_record()
// Input: record - array of Records; cur_pos - current position of Task array
// Output: task_data_report.txt
// - make report txt from entire Task array
void make_txt_from_record(Task records[], int *cur_pos){
	  FILE *fp = fopen("task_data_report", "wt");
	    int i;
		  
		  printf("Making report text file....\n");
		    for(i = 0; i < *cur_pos + 1; i++){
				    fprintf(fp,"task name: %s/class name: %s/release date: %s/due date: %s/task type: %c", records[i].task_name, records[i].class_name, records[i].release_date, records[i].due_date, records[i].task_type);
					  }
			  
			  printf("Making file completed!\n");
			    fclose(fp);
				  return;
}


// Function: print_record()
// Input: record - array of Records; this may contain empty elements in the middle, cur_pos = current position of Task array
// Output: none
// - print records with several options. 'a' for printing all tasks, 'c' for printing tasks with same classes, 't' for printing tasks with same task type, 'd' for printing all tasks until certain due date.
void print_records(Task records[], int *cur_pos){
	  char options = 'a';
	    
	    while(1){
			    printf("Choose an option to print tasks.\n");
				    printf("\'a\' for printing all tasks.\n");
					    printf("\'c\' for printing tasks with same classes.\n");
						    printf("\'t\' for printing tasks with same task type.\n");
							    printf("\'d\' for printing all tasks until certain due date.\n");
								    printf("Choose an option: ");
									    scanf("%c", &options);
										    if(options == 'a'||options == 'c'||options == 't'||options == 'd') break;
											    else{
													      printf("You`ve got wrong input!! The options must be \'a\', \'c\', \'t\' or \'d\'");
														      }
												  }
		  
		  if(options == 'a'){
			      getchar();
				      print_all_records(records, cur_pos);
					    }
		    else{
				    
				    Task filtered[TABLE_SIZE];
					    int filt_size = 0, i;
						    
						    switch(options){
								      case 'c':
										          
										          printf("Input class name you want to find.\n");
												          char* targ_class_name;
														          fgets(targ_class_name, 100, stdin);
																          
																          for(i = 0; i < *cur_pos + 1; i++){
																			            if(strcmp(targ_class_name, records[i].class_name) == 0){
																							            copy_task(&filtered[filt_size++], &records[i]);
																										          }
																						        }
																		          
																		          break;

																				        case 't':
																				         
																				          getchar();
																						          char targ_type = 'a';
																								          
																								          do{
																											            printf("Input a task type you want to find. l for LMS lecture, z for Zoom meeting, a for assignment, e for exam or quiz preparation: ");
																														          scanf("%c", &targ_type);
																																          }
																										          while(isproper_type(targ_type) == 0);

																										          for(i = 0; i < *cur_pos + 1; i++){
																													            if(targ_type == records[i].task_type){
																																	            copy_task(&filtered[filt_size++], &records[i]);
																																				          }
																																        }

																										          break;

																												        case 'd':
																												          
																												          getchar();
																														          int targ_due;

																																          do{
																																			            printf("Input a due date of when you want to find with formed as MMDD: ");
																																						          scanf("%d", &targ_due);
																																								          }
																																		          while(isproper_date(targ_due) == 0);

																																		          for(i = 0; i < *cur_pos + 1; i++){
																																					            if(targ_due >= atoi(records[i].due_date)){
																																									            copy_task(&filtered[filt_size++], &records[i]);
																																												          }
																																								        }

																																		          break;

																																				        default:
																																				          break;
																																						      }

							    for(i = 0; i < filt_size; i++){
									      printf("task name: %s/class name: %s/release date: %s/due date: %s/task type: %c\n",  filtered[i].task_name, filtered[i].class_name, filtered[i].release_date, filtered[i].due_date, filtered[i].task_type);
										      }
								  }
			  return;
}
