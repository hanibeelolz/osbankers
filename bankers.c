#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;
void input();
void show();
void cal();
int main() {
int i, j;
printf(&quot;********** Banker&#39;s Algo ************\n&quot;);
input();
show();
cal();
request();
getch();
return 0;
}
void input() {
int i, j;
printf(&quot;Enter the no of Processes\t&quot;);
scanf(&quot;%d&quot;, &amp;n);
printf(&quot;Enter the no of resources instances\t&quot;);
scanf(&quot;%d&quot;, &amp;r);
printf(&quot;Enter the Max Matrix\n&quot;);
for (i = 0; i &lt; n; i++) {
for (j = 0; j &lt; r; j++) {
scanf(&quot;%d&quot;, &amp;max[i][j]);

}
}
printf(&quot;Enter the Allocation Matrix\n&quot;);
for (i = 0; i &lt; n; i++) {
for (j = 0; j &lt; r; j++) {
scanf(&quot;%d&quot;, &amp;alloc[i][j]);
}
}
printf(&quot;Enter the available Resources\n&quot;);
for (j = 0; j &lt; r; j++) {
scanf(&quot;%d&quot;, &amp;avail[j]);
}
}
void show() {
int i, j;
printf(&quot;Process\t Allocation\t Max\t Available\t&quot;);
for (i = 0; i &lt; n; i++) {
printf(&quot;\nP%d\t &quot;, i + 1);
for (j = 0; j &lt; r; j++) {
printf(&quot;%d &quot;, alloc[i][j]);
}
printf(&quot;\t&quot;);
for (j = 0; j &lt; r; j++) {
printf(&quot;%d &quot;, max[i][j]);
}
printf(&quot;\t&quot;);
if (i == 0) {
for (j = 0; j &lt; r; j++)
printf(&quot;%d &quot;, avail[j]);
}
}
}
void cal() {
int finish[100], temp, need[100][100], flag = 1, k, c1 = 0;

int safe[100];
int i, j;
for (i = 0; i &lt; n; i++) {
finish[i] = 0;
}
//find need matrix
for (i = 0; i &lt; n; i++) {
for (j = 0; j &lt; r; j++) {
need[i][j] = max[i][j] - alloc[i][j];
}
}
printf(&quot;\n&quot;);
while (flag) {
flag = 0;
for (i = 0; i &lt; n; i++) {
int c = 0;
for (j = 0; j &lt; r; j++) {
if ((finish[i] == 0) &amp;&amp; (need[i][j] &lt;= avail[j])) {
c++;
if (c == r) {
for (k = 0; k &lt; r; k++) {
avail[k] += alloc[i][j];
finish[i] = 1;
flag = 1;
}
printf(&quot;P%d-&gt;&quot;, i);
if (finish[i] == 1) {
i = n;
}
}
}
}
}
}
for (i = 0; i &lt; n; i++) {
if (finish[i] == 1) {
c1++;

} else {
printf(&quot;P%d-&gt;&quot;, i);
}
}
if (c1 == n) {
printf(&quot;\n The system is in safe state&quot;);
} else {
printf(&quot;\n Process are in dead lock&quot;);
printf(&quot;\n System is in unsafe state&quot;);
}
}
void request() {
int c, pid, request[100][100], B[100][100], i;
printf(&quot;\n Do you want make an additional request for any of the process ?
(1=Yes|0=No)&quot;);
scanf(&quot;%d&quot;, &amp;c);
if (c == 1) {
printf(&quot;\n Enter process number : &quot;);
scanf(&quot;%d&quot;, &amp;pid);
printf(&quot;\n Enter additional request : \n&quot;);
for (i = 0; i &lt; r; i++) {
printf(&quot; Request for resource %d : &quot;, i + 1);
scanf(&quot;%d&quot;, &amp;request[0][i]);
}
for (i = 0; i &lt; r; i++) {
if (request[0][i] &gt; need[pid][i]) {
printf(&quot;\n ******Error encountered******\n&quot;);
exit(0);
}
}
for (i = 0; i &lt; r; i++) {
avail[i] -= request[0][i];
alloc[pid][i] += request[0][i];
need[pid][i] -= request[0][i];
}

cal();
getch();
} else {
exit(0);
}
}
