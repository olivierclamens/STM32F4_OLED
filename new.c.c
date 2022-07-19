#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void myPrintf(const char *fmt, ...)
{
    static unsigned int posX=1,posY=1;
    int d,x,X,debutFormat,nb0;
    char c;
    float f;
    double lf;
    char msg[200],bloc[20],sNb0[4],*s;
    int i=0,ret,indNb0;
    const char * separators = "\n";
    char * strToken;

    va_list ap;
    va_start(ap, fmt);

    nb0=0;
    debutFormat=0;
    while (*fmt)
    {
        switch (*fmt)
        {
        case '%':
            debutFormat=1;
            break;
        case 'c':               /* char */
            if(debutFormat==1){
                c = (char) va_arg(ap, int);
                ret=sprintf(&msg[i],"%c", c);
                i+=ret;
                debutFormat=0;
            }
            else{
                sprintf(&msg[i],"%c",*(fmt));
                i++;
            }
            break;
        case 's':              /* string */
            if(debutFormat==1){
                s = va_arg(ap, char *);
                ret=sprintf(&msg[i],"%s", s);
                i+=ret;
                debutFormat=0;
            }
            else{
                sprintf(&msg[i],"%c",*(fmt));
                i++;
            }
            break;
        case 'd':
            if(debutFormat==1){
                d = va_arg(ap, int);
                if(nb0==0)
                    ret=sprintf(&msg[i],"%d", d);
                else
                    ret=sprintf(&msg[i],"%0*d",nb0, d);

                i+=ret;
                debutFormat=0;
                nb0=0;
            }
            else{
                sprintf(&msg[i],"%c",*(fmt));
                i++;
            }
            break;
        case 'x':
            if(debutFormat==1){
                x = va_arg(ap, int);
                if(nb0==0)
                    ret=sprintf(&msg[i],"%x", x);
                else
                    ret=sprintf(&msg[i],"%0*x",nb0, x);

                i+=ret;
                debutFormat=0;
                nb0=0;
            }
            else{
                sprintf(&msg[i],"%c",*(fmt));
                i++;
            }
            break;
        case 'X':
            if(debutFormat==1){
                x = va_arg(ap, int);
                if(nb0==0)
                    ret=sprintf(&msg[i],"%X", x);
                else
                    ret=sprintf(&msg[i],"%0*X",nb0, x);

                i+=ret;
                debutFormat=0;
                nb0=0;
            }
            else{
                sprintf(&msg[i],"%c",*(fmt));
                i++;
            }
            break;
        case '0':
            fmt++;
            for(indNb0=0;;indNb0++){
                sNb0[indNb0]=*fmt;
                if(!((*(fmt+1)>='0') && (*(fmt+1)<='9')))
                    break;
                fmt++;
            }
            sNb0[indNb0+1]=0;
            nb0=atoi(sNb0);
            break;


//            case 'l':
//                fmt++;
//                switch(*fmt)
//                {
//                case 'f':
//                    lf = va_arg(ap, double);
//                    ret=sprintf(&msg[i],"%lf", lf);
//                    i+=ret;
//                    break;
//                }

//            case 'f':
//                f = (float)va_arg(ap, double);
//                ret=sprintf(&msg[i],"%f", f);
//                i+=ret;
//                break;



        default:
            sprintf(&msg[i],"%c",*(fmt));
            i++;
        }
        fmt++;

    }
    va_end(ap);

    puts(msg);
//		ssd1306_SetCursor(posX,posY);
//		ssd1306_WriteString(msg, Font_7x10, White);

//    if(strlen(msg)<=18)
//    {
//        ssd1306_SetCursor(posX,posY);
//        ssd1306_WriteString(msg, Font_7x10, White);
//    }
//    else
//    {
//        strToken = strtok ( msg, separators );
//
//        while ( strToken != NULL )
//        {
//            i=0;
//            for(; strlen(strToken+18*i)>=18; i++,posY+=(i*10))
//            {
//                strncpy(bloc,strToken+18*i,18);
//                ssd1306_SetCursor(posX,posY);
//                ssd1306_WriteString(bloc, Font_7x10, White);
//            }
//            strcpy(bloc,strToken+18*i);
//            ssd1306_SetCursor(posX,posY);
//            ssd1306_WriteString(bloc, Font_7x10, White);
//
//            posY+=10;
//            strToken = strtok ( NULL, separators );
//        }
//    }
//    //	// Flush buffer to screen
//    ssd1306_UpdateScreen(&Driver_I2C1);
}
int main()
{
    int val=28;
    myPrintf("radin = %016X\t%018d",val,val);
  //  printf("%0101d",5);
    return 0;
}
