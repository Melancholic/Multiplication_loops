#ifndef LOOP_H
#undef LOOP_H
struct loop{
  loop *next;
  int value;
  loop();
  ~loop();
};
#endif
