/*=========================================================================

  Program: GDCM (Grass Root DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2008 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "gdcmString.h"

#include <iostream>

#include <string.h> // strlen

int TestString2(int argc, char *argv[])
{
  gdcm::String<> s1 = "coucou";
  std::cout << s1 << " -> " << s1.size() << std::endl;

  gdcm::String<> s2 = "coucou!";
  std::cout << s2 << " -> " << s2.size() << std::endl;

  gdcm::String<EOF,64,0> s3 = "coucou";
  std::cout << s3.c_str() << " -> " << s3.size() << std::endl;

  gdcm::String<EOF,64,0> s4 = "coucou!";
  std::cout << s4.c_str() << " -> " << s4.size() << std::endl;

  const char *s = "coucou!";
  gdcm::String<EOF,64,0> s5( s, strlen(s) );
  std::cout << s5.c_str() << " -> " << s5.size() << std::endl;

  std::string ss = "coucou!";
  gdcm::String<EOF,64,0> s6( ss );
  std::cout << s6.c_str() << " -> " << s6.size() << std::endl;

  gdcm::String<EOF,64,0> s7( ss, 1, 5 );
  std::cout << s7.c_str() << " -> " << s7.size() << std::endl;

  gdcm::String<EOF,64,0> s8( ss, 1, 6 );
  std::cout << s8.c_str() << " -> " << s8.size() << std::endl;

  return 0;
}

