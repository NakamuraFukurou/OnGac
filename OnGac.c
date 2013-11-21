/*
 * OnGac.c
 * For Arduino
 * BEEP PLAYER
 */
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

struct {
  int exist;
  char freq[256];
  int highlow;
  char time[256];
} notes;

int main(int argc, char **argv) {
  FILE *fp;
  // ファイルを読み込んだ際のファイルのパスと新たに作成するファイルの名前
  char fullpath[256];
  char filename[256];
  char *p;
  // 出力用
  char s[256][256];
  int i = 0;
  int j = 0;
  double f;
  
  if (argc > 1)
    printf("Filename of Drag&Drop is [%s]\n", argv[1]);
  else {
    printf("NO FILE\n");
    s[0][9] = getchar();
    exit(0);
  }
    
  sprintf(fullpath, "%s", argv[1]);
  if ( (fp = fopen(fullpath, "r")) == NULL ){
    printf("file does NOT open!!");
  }
  p = fullpath;
  p = strlen(p) + p;
  while (*p != '.') {
    p--;
  }
  *p = '\0';
  strcpy(filename, fullpath);
  strcat(filename, ".notes");
  printf("filename = %s\n", filename);
  
  while(fscanf(fp, "%d %s %d %s", &notes.exist, notes.freq, &notes.highlow, notes.time) != EOF) {
	if(strcmp(notes.freq, "C") == 0) {
	  f = 65.40639132514966;
	} else 
	if(strcmp(notes.freq, "Cis") == 0 || strcmp(notes.freq, "Des") == 0) {
	  f = 69.29565774421802;
	} else 
	if(strcmp(notes.freq, "D") == 0) {
	  f = 73.41619197935188;
	} else 
	if(strcmp(notes.freq, "Dis") == 0 || strcmp(notes.freq, "Es") == 0) {
	  f = 77.78174593052023;
	} else 
	if(strcmp(notes.freq, "E") == 0) {
	  f = 82.4068892282175;
	} else 
	if(strcmp(notes.freq, "F") == 0) {
	  f = 87.30705785825097;
	} else 
	if(strcmp(notes.freq, "Fis") == 0 || strcmp(notes.freq, "Ges") == 0) {
	  f = 92.4986056779086;
	} else 
	if(strcmp(notes.freq, "G") == 0) {
	  f = 97.99885899543733;
	} else 
	if(strcmp(notes.freq, "Gis") == 0 || strcmp(notes.freq, "As") == 0) {
	  f = 103.82617439498628;
	} else 
	if(strcmp(notes.freq, "A") == 0) {
	  f = 110;
	} else 
	if(strcmp(notes.freq, "Ais") == 0 || strcmp(notes.freq, "B") == 0) {
	  f = 116.54094037952248;
	} else 
	if(strcmp(notes.freq, "H") == 0) {
	  f = 123.47082531403103;
	} else {
	  printf("%s is NOT note, program is HALT in LINE %d\n", notes.freq, i+1);
	  s[0][9] = getchar();
	  fclose(fp);
	  exit(0);
	}
	f *= pow(2, notes.highlow-1);
	f += 0.5;
    sprintf(s[i], "{ %d, %d, %s}", notes.exist, (int)(f), notes.time);
    i++;
  }
  fclose(fp);
  
  
  if ( (fp = fopen(filename, "w")) == NULL){
    printf("Cannot open this file (%s)", filename);
    exit(-1);
  } else {
	fprintf(fp, "_notes notes[%d] = {\n", i);
    for(j = 0; j < i; j++){
	  fprintf(fp, "  %s", s[j]);
	  if((i-1) != j) 
	    fprintf(fp, ",\n");
	}
	fprintf(fp, "\n};\n");
  }
  fclose(fp);
  
  return 0;
}