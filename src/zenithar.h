
/**
 * @brief Ask user for input
 * 
 * @param prompt {char *} : prompt string
 * @param buffer {char *} : buffer into which store user input
 * @param bufferSize {int} : size of the buffer
 * @return signed char 
 */
signed char getSecureInput(char *prompt, char *buffer, int bufferSize);

/**
 * @brief Ask user specifically for an int
 * 
 * @param prompt {char *} : prompt string
 * @param bufferSize {int} : buffer size
 * @return int : input integer
 */
int getSecureInputInt(char *prompt, int bufferSize);

/**
 * @brief Ask user specifically for a signed char (string)
 * 
 * @param prompt {char *} : prompt string
 * @param bufferSize {int} : size of the buffer
 * @return signed char : input string
 */
signed char *getSecureInputSignedChar(char *prompt, int bufferSize);