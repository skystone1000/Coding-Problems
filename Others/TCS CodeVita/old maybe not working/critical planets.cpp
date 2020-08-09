int [] product (int [] input) {
int [] front = new int[input.length];
int [] rear = new int[input.length];
int [] output = new int[input.length];
front[0] = 1;
rear[input.length-1] =1;
for(int i = 1; i < input.length; i++)
front[i] = front[i-1]*input[i-1];
for(int i = input.length-2; i >=0; i--)
rear[i] = rear[i+1]*input[i+1];
for(int i = 0;i<input.length;i++)
output[i] = front[i]*rear[i];
return output;
}