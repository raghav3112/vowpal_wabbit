// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "action_score.h"

#include "v_array.h"
#include "io_buf.h"
#include "global_data.h"

namespace ACTION_SCORE
{
void print_action_score(VW::io::writer* f, const v_array<action_score>& a_s, const v_array<char>& tag)
{
  if (f == nullptr)
  {
    return;
  }

  std::stringstream ss;

  for (size_t i = 0; i < a_s.size(); i++)
  {
    if (i > 0)
      ss << ',';
    ss << a_s[i].action << ':' << a_s[i].score;
  }
  print_tag_by_ref(ss, tag);
  ss << '\n';
  const auto ss_str = ss.str();
  ssize_t len = ss_str.size();
  ssize_t t = f->write(ss_str.c_str(), (unsigned int)len);
  if (t != len)
    std::cerr << "write error: " << VW::strerror_to_string(errno) << std::endl;
}

void delete_action_scores(void* v)
{
  v_array<action_score>* cs = (v_array<action_score>*)v;
  cs->delete_v();
}

}  // namespace ACTION_SCORE
