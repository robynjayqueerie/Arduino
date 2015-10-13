void getREGISTERS()
{
   byte contador;
   for(contador =0; contador<TOTAL_NO_OF_REGISTERS; contador++)
   {
     Serial.print(regs[contador],16);
     Serial.print(',');
   }
   Serial.println(contador);
}

void getStatus()
{
  unsigned char contador;
  //Serial.println("******");
  for (contador=0; contador<TOTAL_NO_OF_PACKETS;contador++){
  Serial.print("[");
  Serial.print(packets[contador].requests);
  Serial.print(",");
  Serial.print(packets[contador].successful_requests);
  Serial.print(",");
  Serial.print(packets[contador].failed_requests);
  Serial.print(",");
  Serial.print(packets[contador].exception_errors);
  Serial.print("]");
  }
  Serial.println(contador);
}

void setDebug()
{
  char *arg;  
  arg = _myMonitor.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL)      // As long as it existed, take it
  {
    if (arg[0] == '1')  set_debug(true);
    else set_debug(false);
  }
  else Serial.println(get_debug());
}

void setTimeOut()
{
  char *arg;
  arg = _myMonitor.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL)      // As long as it existed, take it
  {
    long value = atoi(arg);
    set_timeout (value);
  }
  else Serial.println(get_timeout());
}

void setPolling()
{
  char *arg;
  arg = _myMonitor.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL)      // As long as it existed, take it
  {
    long value= atoi(arg);
    set_polling (value);
  }
  else Serial.println(get_polling());
}
void setRetries()
{
  char *arg;
  arg = _myMonitor.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL)      // As long as it existed, take it
  {
    unsigned char value = atoi(arg);
    set_retry_count(value);
  }
  else Serial.println(get_retry_count());
}

void miMonitor()
{
  Serial.println("eMaster>"); 
}



