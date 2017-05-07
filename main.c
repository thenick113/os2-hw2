// CS 444 - HW#2

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define NUM_FORKS 5

//Data Structures:
//left fork
//right fork
struct sector {
    int left_fork;
    int right_fork;
}

//Request
//do_work_mutex_index
//Sector address
struct request {
    int do_work_mutex_index;
    int sector_index;
}

//Memory accessor
//Current sector index
//Current spin directino
//Array of sectors
struct memory_accessor {
    int current_sector_index;
    int current_spin_direction; //up 1, down -1
    sector[5] sectors = {
        {5, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
    }
}

//Buffer to hold requests
//LOOK methods interact with this struct
struct buffer {
    
}

// Insert a new request into the buffer
void insert_request(request *r, buffer *b){
    
}

request* get_next_request(buffer *b){
    
}

void remove_request(request *r, buffer *b){
    
}

//Define the mutexes
pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER

//DoWorks
pthread_mutex_t do_work_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t do_work_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t do_work_3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t do_work_4 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t do_work_5 = PTHREAD_MUTEX_INITIALIZER;

//Forks
static pthread_mutex_t forks[NUM_FORKS] = {
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER
};

pthread_mutex_t fork_1 = PTHREAD_MUTEX_INITIALIZER
pthread_mutex_t fork_2 = PTHREAD_MUTEX_INITIALIZER
pthread_mutex_t fork_3 = PTHREAD_MUTEX_INITIALIZER
pthread_mutex_t fork_4 = PTHREAD_MUTEX_INITIALIZER
pthread_mutex_t fork_5 = PTHREAD_MUTEX_INITIALIZER


void *ps(void *param)
{
    char phi = *(char *)param;
    int left,right;
    int do_work_mutex_index;
    swith (phi)
    case A:
        left = 5;
        right = 1;
        do_work_mutex_index = 1;
        break;
    case B:
        left = 1;
        right = 2;
        do_work_mutex_index = 2;
        break;
    case C:
        left = 2;
        right = 3;
        do_work_mutex_index = 3;
        break;
    case D:
        left = 3;
        right = 4;
        do_work_mutex_index = 4;
        break;
    case E:
        left = 4;
        right = 5;
        do_work_mutex_index = 5;
        break;
    default:
        return;
    
    while(1){
        think();
        get_forks(left, right, do_work_mutex_index);
        eat();
        put_forks(left, right);
    }
}

void think(){
    //Sleep for 1-20 seconds
    //printf("Philospher X is thinking");
    int sleepTime = (genrand_int32() % 21) + 1;
    sleep(sleepTime);
}

void get_forks(int left, int right, int do_work_mutex_index){
    //Lock on buffer access
    pthread_mutex_lock(&buffer_mutex);
    
    //Write request to buffer
    //Include sector address
    //Include pointer to the philosophes "DoWork_Mutex"
    
    //Lock on "DoWork_Mutex"
    
    //Lock each fork in the given sector
    
    //Unlock DoWork_Mutex
}

void eat()
{
    //Sleep for 2-9 seconds
    //printf("Philospher X is eating");
    int sleepTime = (genrand_int32() % 10) + 2;
    sleep(sleepTime);
}

void put_forks(int left, int right){
    // Unlock access to each fork in the given sector
    pthread_mutex_unlock(&forks[left]);
    pthread_mutex_unlock(&forks[right]);
}

int main() {
    
    pthread_t A,B,C,D,E;
    
    pthread_creat(&A,NULL,ps,"A");
    pthread_creat(&B,NULL,ps,"B");
    pthread_creat(&C,NULL,ps,"C");
    pthread_creat(&D,NULL,ps,"D");
    pthread_creat(&E,NULL,ps,"E");
    
    memory_accessor memory_access = malloc(sizeof(struct memory_accessor));
    memory_access -> current_sector_index = 0;
    memory_access -> current_spin_direction = 1; // going up
    
    
    //The LOOK algorithm for buffer management
    while(1){
        //Lock access to the buffer
        //Block until access is gained
        pthread_mutex_lock(&buffer_mutex);
        
        //Try to service the next request
        //Consider current direction
        //Check if reached turning point or end of buffer
        
        
        //Check if the current request has both forks available
        //If so, unlock the current request's philosopher's "DoWork_Mutex"
        
        //Lock on current request's philosopher's "DoWork_Mutex"
        
        //Unlock access to the buffer
        
    }
    
    return 0;
}




// Producer function
void *producer(void * item){
   unsigned long producingItem;
   unsigned long sleepTime;
  struct item *itemToProduce;
  
  // Process loop
  while(1){
    producingItem = 1;
   // printf("producer start to sleep\n");
    // Waits 3-7s before trying to add to the buffer
    sleepTime = (genrand_int32() % 5) + 3;
    sleep(sleepTime);
    
    // Produce item to add to the buffer
    // Some number that will be printed
    // Sleep time for consumer between 2 - 9
    itemToProduce = (struct item*) malloc(sizeof(struct item));
    itemToProduce -> numToPrint = genrand_int32();
    itemToProduce -> timeToSleep = (genrand_int32() % 8) + 2;
      
    // Stack access loop
    while(producingItem){
        // Block until buffer mutex is available to lock
      pthread_mutex_lock(&buffer_mutex);
      
      // Check if buffer is full
      if(isBufferFull()){
        // Unblock access to buffer
            pthread_mutex_unlock(&buffer_mutex);
        
        // Sleep a minimum amount of time
        sleep(1);
        
      }else{
//        printf("Producing item: ^?\n");
//          display_item(*itemToProduce);
        
        // Add item to buffer
        enqueue(*itemToProduce);
        
        // Free resources
        free(itemToProduce);
        
        // Unblock access to the buffer
        pthread_mutex_unlock(&buffer_mutex);
        
        //Finish producing current item
        producingItem = 0;
        }
    }
  }
  
  return;
}
  





/*********************************************************/
/*********************** G-rand **************************/
/*********************************************************/
/* initializes state[N] with a seed */
void init_genrand(unsigned long s)
{
    int j;
    state[0]= s & 0xffffffffUL;
    for (j=1; j<N; j++) {
        state[j] = (1812433253UL * (state[j-1] ^ (state[j-1] >> 30)) + j);
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array state[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        state[j] &= 0xffffffffUL;  /* for >32 bit machines */
    }
    left = 1; initf = 1;
}

/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
/* slight change for C++, 2004/2/26 */
void init_by_array(unsigned long init_key[], int key_length)
{
    int i, j, k;
    init_genrand(19650218UL);
    i=1; j=0;
    k = (N>key_length ? N : key_length);
    for (; k; k--) {
        state[i] = (state[i] ^ ((state[i-1] ^ (state[i-1] >> 30)) * 1664525UL))
          + init_key[j] + j; /* non linear */
        state[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i>=N) { state[0] = state[N-1]; i=1; }
        if (j>=key_length) j=0;
    }
    for (k=N-1; k; k--) {
        state[i] = (state[i] ^ ((state[i-1] ^ (state[i-1] >> 30)) * 1566083941UL))
          - i; /* non linear */
        state[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i>=N) { state[0] = state[N-1]; i=1; }
    }

    state[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */
    left = 1; initf = 1;
}

static void next_state(void)
{
    unsigned long *p=state;
    int j;

    /* if init_genrand() has not been called, */
    /* a default initial seed is used         */
    if (initf==0) init_genrand(5489UL);

    left = N;
    next = state;

    for (j=N-M+1; --j; p++)
        *p = p[M] ^ TWIST(p[0], p[1]);

    for (j=M; --j; p++)
        *p = p[M-N] ^ TWIST(p[0], p[1]);

    *p = p[M-N] ^ TWIST(p[0], state[0]);
}

/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void)
{
    unsigned long y;

    if (--left == 0) next_state();
    y = *next++;

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}

/* generates a random number on [0,0x7fffffff]-interval */
long genrand_int31(void)
{
    unsigned long y;

    if (--left == 0) next_state();
    y = *next++;

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return (long)(y>>1);
}

/* generates a random number on [0,1]-real-interval */
double genrand_real1(void)
{
    unsigned long y;

    if (--left == 0) next_state();
    y = *next++;

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return (double)y * (1.0/4294967295.0);
    /* divided by 2^32-1 */
}

/* generates a random number on [0,1)-real-interval */
double genrand_real2(void)
{
    unsigned long y;

    if (--left == 0) next_state();
    y = *next++;

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return (double)y * (1.0/4294967296.0);
    /* divided by 2^32 */
}

/* generates a random number on (0,1)-real-interval */
double genrand_real3(void)
{
    unsigned long y;

    if (--left == 0) next_state();
    y = *next++;

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return ((double)y + 0.5) * (1.0/4294967296.0);
    /* divided by 2^32 */
}

/* generates a random number on [0,1) with 53-bit resolution*/
double genrand_res53(void)
{
    unsigned long a=genrand_int32()>>5, b=genrand_int32()>>6;
    return(a*67108864.0+b)*(1.0/9007199254740992.0);
}
/* These real versions are due to Isaku Wada, 2002/01/09 added */
