//
//  BitField.c
//  Bit field on C
//
//  Created by Denis Andreev on 20/04/2017.
//  Copyright © 2017 Denis Andreev. All rights reserved.
// 


#include <stdio.h>
#include <stdlib.h>

typedef struct ip_addr
{
	unsigned short oct_one : 8;
	unsigned short oct_two : 8;
	unsigned short oct_three : 8;
	unsigned short oct_four : 8;
} ip_addr;

ip_addr
*get_ip_from_int(int ip) {
	ip_addr *ip_res = (ip_addr*)malloc(sizeof(ip_addr));
	ip_res->oct_one = (ip&0xFF000000) >> 24;
	ip_res->oct_two = (ip&0x00FF0000) >> 16;
	ip_res->oct_three = (ip&0x0000FF00) >> 8;
	ip_res->oct_four = ip&0x000000FF;
	return ip_res;
}

ip_addr 
*add_ip(int one, int two, int three, int four) {
	ip_addr *ip_res = (ip_addr*)malloc(sizeof(ip_addr));
	ip_res->oct_one = one;
	ip_res->oct_two = two;
	ip_res->oct_three = three;
	ip_res->oct_four = four;
	return ip_res;
}

int
get_int_from_ip(ip_addr *ip){
	int result = (ip->oct_one << 24) | (ip->oct_two << 16) | (ip->oct_three << 8) | ip->oct_four;
	return result;
}

int main(int argc, char const *argv[])
{
	ip_addr *ip_a = add_ip(192,168,2,120);
	int ip_i = get_int_from_ip(ip_a);
	printf("%i\n", ip_i);	
	ip_addr *conv = get_ip_from_int(ip_i+20); // get ip from int but we add 20 to integer
	printf("IP:%i.%i.%i.%i\n", conv->oct_one, conv->oct_two, conv->oct_three, conv->oct_four); 
	return 0;
}