#ifndef BLYNKPARAMSTORE
#define BLYNKPARAMSTORE value
#include <Blynk/BlynkParam.h>

class BlynkParamPlus
    : public BlynkParam
{
public:
  explicit
  BlynkParamPlus()
      : BlynkParam(malloc(sizeof(BLYNK_PARAM_PLACEHOLDER_64)), 0, sizeof(BLYNK_PARAM_PLACEHOLDER_64))
  {}
    BlynkParamPlus operator=(const BlynkParam param);
    BlynkParamPlus operator=(int param);
    BlynkParamPlus operator=(float param);
    BlynkParamPlus operator=(const char* param);
    BlynkParamPlus operator=(char* param);
    BlynkParamPlus operator+(const BlynkParam param);

private:
    void reset();
};

inline void BlynkParamPlus::reset(){
  len=0;
  *buff = '\0';
}

inline
BlynkParamPlus BlynkParamPlus::operator+(const BlynkParam param)
{
  for (int i = 0; param[i] < param.end(); ++i) {
    if (param[i].isValid()) {
      // Serial.print("Add param[");
      // Serial.print(i);
      // Serial.print("] = ");
      // Serial.println(param[i].asStr());
      add(param[i].asStr());
    } else {
      // Serial.print("param[");
      // Serial.print(i);
      // Serial.println("] exceeds limit, break");
      break;
    }
  }
  return *this;
}

inline
BlynkParamPlus BlynkParamPlus::operator=(const BlynkParam param)
{
  this->reset();
  return *this + param;
}

inline
BlynkParamPlus BlynkParamPlus::operator=(int param)
{
  this->reset();
  this->add(param);
  return *this;
}

inline
BlynkParamPlus BlynkParamPlus::operator=(float param)
{
  this->reset();
  this->add(param);
  return *this;
}

inline
BlynkParamPlus BlynkParamPlus::operator=(char* param)
{
  this->reset();
  this->add(param);
  return *this;
}

inline
BlynkParamPlus BlynkParamPlus::operator=(const char* param)
{
  this->reset();
  this->add(param);
  return *this;
}

#endif
