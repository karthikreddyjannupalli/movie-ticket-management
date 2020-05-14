#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;time.h&gt;
#include &lt;sys/time.h&gt;
typedef struct node
{
    int r;
    int c;
    struct node* next;
} node;
struct stack{
char rev[100];
struct stack *next;
};
struct stack *top=NULL;
void push(char r[]){
struct stack *temp=(struct stack*)malloc(sizeof(struct
stack));
if(top==NULL)

{
strcpy(temp-&gt;rev,r);
temp-&gt;next=NULL;
top=temp;
}
else{strcmp(temp-&gt;rev,r);
temp-&gt;next=top;
top=temp;
}
}
void pop(){
while(top!=NULL){
    printf(&quot;%s&quot;,top-&gt;rev);
    top=top-&gt;next;
}
}

void review(int sel){
FILE *rev;
char ch;
int i;
rev =fopen(&quot;rev.txt&quot;,&quot;r&quot;);
for(i=1;i&lt;sel;i++){
while(ch=(fgetc(rev)!=&#39;\n&#39;)){
}
}
ch=fgetc(rev);
i=1;

char c=&#39;1&#39;;
char r[100]={&#39; &#39;};
printf(&quot;\nReview\n&quot;);
r[0]=&#39;1&#39;;
while(ch!=&#39;\n&#39;){
    ch=fgetc(rev);
    if(ch==&#39;.&#39;){
        c++;
        r[i]=c;
        i++;
        continue;
    }
    r[i]=ch;
    i++;
}
push(r);
pop();
}

void insert(node** head,int r,int c)
{
    node* p=(*head);
    node* temp=(node*)malloc(sizeof(node));
    temp-&gt;c=c;
    temp-&gt;r=r;
    temp-&gt;next=NULL;
    if(p==NULL)
    {

        (*head)=temp;
        return;
    }
    while(p-&gt;next!=NULL)
        p=p-&gt;next;
    p-&gt;next=temp;
    return;
}
void display(node* head)
{
    node* p=head;
    while(p!=NULL)
    {
        printf(&quot;%d-%d &quot;,p-&gt;r,p-&gt;c);
        p=p-&gt;next;
    }
    printf(&quot;\n&quot;);
}
int countofseats(int sel,char *help)
{
    FILE* fout;
    FILE* ftemp;
    char ch;
    int r,c;
    fout=fopen(help,&quot;a+&quot;);
    ftemp=fopen(&quot;temp.txt&quot;,&quot;w+&quot;);
    node* head=NULL;
    for(int i=1;i&lt;sel;i++)
    while((ch=fgetc(fout))!=&#39;\n&#39;);

    while((ch=fgetc(fout))!=&#39; &#39;);
    while((ch=fgetc(fout))!=&#39;\n&#39;)
    {
        //printf(&quot;%c&quot;,ch);
        r=(int)ch-&#39;0&#39;;
        fgetc(fout);
        c=(int)fgetc(fout)-&#39;0&#39;;
        insert(&amp;head,r,c);
        char c=fgetc(fout);
        if(c==&#39;\n&#39;)
            break;
    }
    int res=0;
    while(head!=NULL)
    {
        res=res+1;
        head=head-&gt;next;
    }
    return res;
}
void msort(node** head)
{
    int temp;
    node* p=(*head);
    node*q=(*head);
    node* t=(*head);
    while(p!=NULL)
    {
        q=p;
        while(q!=NULL)

        {
            if(q-&gt;r &lt; p-&gt;r)
            {
                temp=q-&gt;r;
                q-&gt;r=p-&gt;r;
                p-&gt;r=temp;
                temp=q-&gt;c;
                q-&gt;c=p-&gt;c;
                p-&gt;c=temp;
            }
            else if(q-&gt;r==p-&gt;r)
            {
                if(q-&gt;c &lt; p-&gt;c)
                {
                    temp=p-&gt;c;
                    p-&gt;c=q-&gt;c;
                    q-&gt;c=temp;
                }
            }
            q=q-&gt;next;
        }
        p=p-&gt;next;
    }
    (*head)=t;
}
void delay(int number_of_seconds)
{
   int milli_seconds = 10 * number_of_seconds;
   clock_t start_time = clock();
  while (clock() &lt; start_time + milli_seconds);
}

void display_Front_page()
{
    for(int i=0;i&lt;80;i++)
    {
        printf(&quot;=&quot;);
        delay(1);
    }
    for(int i=0;i&lt;10;i++)
     printf(&quot;\n&quot;);
     printf(&quot;\t\tMOVIE TICKET BOOKING SYSTEM\n&quot;);
     for(int i=0;i&lt;10;i++)
     printf(&quot;\n&quot;);
for(int i=0;i&lt;80;i++)
    {
        printf(&quot;=&quot;);
        delay(1);
    }
}
void show_Menu()
{
    for(int i=0;i&lt;80;i++)
    {
        printf(&quot;=&quot;);
        delay(1);
    }
    printf(&quot;MOVIES RUNNING NOW ARE:\n&quot;);
        printf(&quot;\n 1. Interstellar\n 2.Joker\n 3.Dunkirk\n
4.RRR\n&quot;);
    for(int i=0;i&lt;80;i++)
    {
        printf(&quot;=&quot;);

        delay(1);
    }
}
int theater(int sel,char *folder,char* req)
{
    int t;
TIME:
    printf(&quot;enter time of show:\n&quot;);
    printf(&quot;enter 1 -&gt; 11:00am&quot;);
    printf(&quot;enter 2 -&gt; 02:00pm&quot;);
    printf(&quot;enter 3 -&gt; 06:00pm&quot;);
    printf(&quot;enter 4 -&gt; 09:00pm&quot;);
    scanf(&quot;%d&quot;,&amp;t);
char
help[100]=&quot;C:\\Users\\USER\\Documents\\algorm\\New
folder\\&quot;;
    strcat(help,req);
    switch(t)
    {
    case 1:
        strcat(help,&quot;\\theater1.txt&quot;);
        break;
    case 2:
        strcat(help,&quot;\\theater2.txt&quot;);
        break;
    case 3:
        strcat(help,&quot;\\theater3.txt&quot;);
        break;
    case 4:
        strcat(help,&quot;\\theater4.txt&quot;);
        break;

    }
    FILE* fout;
    fout=fopen(help,&quot;a+&quot;);
    fprintf(fout,&quot;Interstellar \nJoker \nDunkirk \nRRR \n&quot;);
    fclose(fout);
    int ava=100-countofseats(sel,help);
    printf(&quot;enter the no of seats&quot;);
    int no;
    scanf(&quot;%d&quot;,&amp;no);
    if(no&gt;ava)
    {
        printf(&quot;no of seats is less\n&quot;);
        printf(&quot;enter 1 to change time\n enter 2 to change
movie \n else anything to exit&quot;);
        int ted;
        scanf(&quot;%d&quot;,&amp;ted);
        if(ted==1)
        {
            system(&quot;cls&quot;);
            goto TIME;
        }
        else if(ted ==2)
            return 0;
        else
        {
            printf(&quot;THANK YOU\n&quot;);
            exit(0);
        }
    }
    //printf(&quot;%s&quot;,help);

    char m[20],seat[100];
    switch(sel){
case 1:
    strcpy(m,&quot;Interstellar&quot;);
    break;
case 2:
    strcpy(m,&quot;Joker&quot;);
    break;
case 3:
    strcpy(m,&quot;Dunkirk&quot;);
    break;
case 4:
    strcpy(m,&quot;RRR&quot;);
    break;
    }
    char s[20];
    char ch;
    fout=fopen(help,&quot;a+&quot;);
      int n=10,r,c,i=0;
    for(int i=1;i&lt;sel;i++)
    while((ch=fgetc(fout))!=&#39;\n&#39;);
    fscanf(fout,&quot;%s&quot;,&amp;s);
    printf(&quot;%s&quot;,s);
    if(strcmp(m,s)==0)
    {
    fscanf(fout,&quot;%d%d&quot;,&amp;r,&amp;c);
    printf(&quot;\n&quot;);
    for(int i=0;i&lt;n;i++)
    {

        for(int j=0;j&lt;n;j++)
        {
            if(i==r &amp;&amp; j==c)
            {
                printf(&quot;%c%d-%d &quot;,177,i,j);
                fscanf(fout,&quot;%d %d&quot;,&amp;r,&amp;c);
            }
            else
            printf(&quot;%c%d-%d &quot;,254,i,j);
        }
        printf(&quot;\n&quot;);
    }
    printf(&quot;enter the seat\n&quot;);
    fflush(stdin);
    for (int i=0;i&lt;no;i++)
{
    gets(seat);
    //printf(&quot;%s&quot;,seat);
   FILE* ftemp;
   fclose(fout);
    fout=fopen(help,&quot;a+&quot;);
    ftemp=fopen(&quot;temp.txt&quot;,&quot;w+&quot;);
    for(int i=1;i&lt;=sel;i++)
    {while((ch=fgetc(fout))!=&#39;\n&#39;)
    {
        fputc(ch,ftemp);
    }
    if(i!=sel)
    fputc(&#39;\n&#39;,ftemp);
    }
    fputc(&#39; &#39;,ftemp);

    fputs(seat,ftemp);
    fputc(&#39;\n&#39;,ftemp);
    while((ch=fgetc(fout))!=EOF)
    {
        fputc(ch,ftemp);
    }
    //fgetpos(fout,&amp;pos);
    fclose(fout);
    fout=fopen(help,&quot;w+&quot;);
    fseek(ftemp,0,0);
    while((ch=fgetc(ftemp))!=EOF)
    {
        fputc(ch,fout);
    }
    fclose(fout);
    fclose(ftemp);
    fout=fopen(help,&quot;a+&quot;);
    ftemp=fopen(&quot;temp.txt&quot;,&quot;w+&quot;);
    node* head=NULL;
    for(int i=1;i&lt;sel;i++)
    while((ch=fgetc(fout))!=&#39;\n&#39;)
        fputc(ch,ftemp);
    if(sel!=1){
    fputc(&#39;\n&#39;,ftemp);
}
    while((ch=fgetc(fout))!=&#39; &#39;);
    while((ch=fgetc(fout))!=&#39;\n&#39;)
    {
        //printf(&quot;%c&quot;,ch);
        r=(int)ch-&#39;0&#39;;
        fgetc(fout);

        c=(int)fgetc(fout)-&#39;0&#39;;
        insert(&amp;head,r,c);
        char c=fgetc(fout);
        if(c==&#39;\n&#39;)
            break;
    }
    //display(head);
    msort(&amp;head);
    //display(head);
    fclose(fout);
    fout=fopen(help,&quot;a+&quot;);
    for(int i=1;i&lt;sel;i++)
    while((ch=fgetc(fout))!=&#39;\n&#39;);
    while((ch=fgetc(fout))!=&#39; &#39;)
    {
        fputc(ch,ftemp);
    }
    while(head!=NULL)
    {
        fputc(&#39; &#39;,ftemp);
        fputc(head-&gt;r+&#39;0&#39;,ftemp);
        fputc(&#39; &#39;,ftemp);
        fputc(head-&gt;c+&#39;0&#39;,ftemp);
        head=head-&gt;next;
    }
    fputc(&#39;\n&#39;,ftemp);
    while((ch=fgetc(fout))!=&#39;\n&#39;);
    while((ch=fgetc(fout))!=EOF)
        fputc(ch,ftemp);
    fclose(ftemp);

    fclose(fout);
    ftemp=fopen(&quot;temp.txt&quot;,&quot;r&quot;);
    fout=fopen(help,&quot;w+&quot;);
    while((ch=fgetc(ftemp))!=EOF)
    {
        fputc(ch,fout);
    }
    fclose(fout);
    fclose(ftemp);
}
}
return no;
}
void main()
{
    int i=0,j=0,sel;
    time_t current_time;
    char* strtime;
    FILE* file;
    char req[15]={&#39; &#39;};
    display_Front_page();
    printf(&quot;\nEnter the month date(Oct dd yyyy)\n&quot;);
    scanf(&quot;%s&quot;,&amp;req);
    system(&quot;cls&quot;);
        req[9+j]=&#39;\0&#39;;
    char foldername[25]={&#39;m&#39;,&#39;k&#39;,&#39;d&#39;,&#39;i&#39;,&#39;r&#39;,&#39; &#39;,&#39;\0&#39;};
    strcat(foldername,req);
    //printf(&quot;%s&quot;,req);
    system(foldername);
BOOKMOVIE:
        show_Menu();

    scanf(&quot;%d&quot;,&amp;sel);
    review(sel);
    int con=0;
    printf(&quot;would you like to continue:press 1\n&quot;);
    scanf(&quot;%d&quot;,&amp;con);
    int ta;
    char
help[100]=&quot;C:\\Users\\USER\\Documents\\algorm\\New
folder\\&quot;;
    if(con==1)
    {
        ta=theater(sel,foldername,req);
        if(ta==0)
        {
            system(&quot;cls&quot;);
            goto BOOKMOVIE;
        }
    }
    else
    {
        system(&quot;cls&quot;);
        goto BOOKMOVIE;
    }
    if(ta&gt;0)
    {
        printf(&quot;Money to be paid: %0.2f\n&quot;,(float)(100)*ta);
        printf(&quot;THANK YOU\n&quot;);
    }
    printf(“&lt;&lt;&lt;&lt;&lt;&lt;&lt;&lt;&lt;&lt;EXIT&gt;&gt;&gt;&gt;&gt;&gt;&gt;\n”);
