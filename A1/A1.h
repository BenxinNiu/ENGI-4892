#include <string>

struct infor{
int *pointer_array;
int size;
int max;
int min;
double avg;
};

/**
	 * Extract information from the input file
	 * create an array of struct
	 *
	 * @param   none
	 * @return   none
	 */
void extract();

/**
	 * Display desired information of the array of struct
	 *
	 * @param   none
	 * @return   none
	 */
void display_infor(infor a);

/**
	 * calculate the minimun value in the array
	 * return the value
	 *
	 * @param   *arr pointer to the array of integers
   * @param size the size of the array
	 * @return   the minimun value in integer
	 */
int minimun(int *arr, int size);

/**
	 * calculate the maximun value in the array
	 * return the value
	 *
	 * @param   *arr pointer to the array of integers
   * @param size the size of the array
	 * @return   the maximun value in integer
	 */
int maximum(int *arr,int size);

/**
	 * calculate the average value of the array
	 * return the double value
	 *
	 * @param   *arr pointer to the array of integers
   * @param size the size of the array
	 * @return   the average value in double
	 */
double average(int *arr,int size);
