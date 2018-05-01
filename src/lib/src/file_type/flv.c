#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "common_priv.h"

#define SIG_FLV_1 0x46
#define SIG_FLV_2 0x4C
#define SIG_FLV_3 0x56

type_e stegx_test_file_flv(FILE* file){
	if(file==NULL) return UNKNOWN;
	fseek(file,0,SEEK_SET);
	int i;
	uint8_t sig;
	int read;
	uint8_t tab_sig_flv[3]={SIG_FLV_1, SIG_FLV_2, SIG_FLV_3};
	for(i=0;i<3;i++){
		read=fread(&sig,sizeof(uint8_t),1,file);
		if(sig!=tab_sig_flv[i]){
			return UNKNOWN;
		}
	}
	return FLV;
}