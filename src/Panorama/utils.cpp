// -*- c-basic-offset: 4 -*-

/** @file utils.cpp
 *
 *  @author Pablo d'Angelo <pablo.dangelo@web.de>
 *
 *  $Id$
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This software is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public
 *  License along with this software; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifdef WIN32
    #include <sys/utime.h>
#else
    #include <sys/time.h>
#endif
#include <time.h>
#include <stdio.h>
#include "common/utils.h"

#ifdef unix
std::string utils::CurrentTime()
{
  char tmp[100];
  struct tm t;
  struct timeval tv;
  gettimeofday(&tv,NULL);
  localtime_r(&tv.tv_sec, &t);
  strftime(tmp,99,"%H:%M:%S",&t);
  sprintf(tmp+8,".%06ld",tv.tv_usec);
  return tmp;
}
#else
std::string utils::CurrentTime()
{
    // FIXME implement for Win & Mac
    return "";
}
#endif

std::string utils::doubleToString(double d)
{
    char c[10];
    std::sprintf (c, "%.3f", d);
    std::string number (c);

    int l = number.length()-1;

    while ( l != 0 && number[l] == '0' ) {
      number.erase (l);
      l--;
    }
    if ( number[l] == ',' ) {
      number.erase (l);
      l--;
    }
    if ( number[l] == '.' ) {
      number.erase (l);
      l--;
    }

    return number;
}

