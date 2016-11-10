/******************************************************************************
 *
 *
 *
 *
 * Copyright (C) 1997-2015 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby
 * granted. No representations are made about the suitability of this software
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */

#include "doxygen.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

/*! \file
 *  \brief main entry point for doxygen
 *
 *  This file contains main()
 */

/*! Default main. The idea of separating this from the rest of doxygen,
 *  is to make it possible to write your own main, with a different
 *  generateOutput() function for instance.
 */
int main(int argc,char **argv)
{
  remove( "functionNameList.txt" );
  
  char cCurrentPath[FILENAME_MAX];
  if (!getcwd(cCurrentPath, sizeof(cCurrentPath)))
    {
      return errno;
    }

  cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
  printf ("The current working directory is %s", cCurrentPath);
  
  initDoxygen();
  readConfiguration(argc,argv);
  checkConfiguration();
  adjustConfiguration();
  parseInput();
  generateOutput();
  return 0;
}

