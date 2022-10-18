#ifndef MY_DEFINITIONS_HEADER
#define MY_DEFINITIONS_HEADER

/*******************************************************************************
* File:     commonDefs.h
* Purpose:  common definitions 
* Course:   bsy
* Author:   M. Thaler, 2011
* Revision: 5/2012, 7/2013, 4/2014
* Version:  v.fs20
*******************************************************************************/

#define MYTURN_SEMAPHOR  "/my_semaphor_1_name_simple_seq"
#define COIN_SEMAPHOR    "/my_semaphor_2_name_simple_seq"
#define COFFEE_SEMAPHOR  "/my_semaphor_3_name_simple_seq"
#define READY_SEMAPHOR   "/my_semaphor_4_name_simple_seq"

#define ITERS    (100*1000*1000)
#define CUSTOMERS 4

//******************************************************************************

#define checkSem(sem)  {if (sem == SEM_FAILED) {perror("sem_open"); exit(-1);}}

#define drinkingCoffee(id) {usleep((((1+id)*rand())+100000)&0xFFFFF);}

//******************************************************************************

#endif

