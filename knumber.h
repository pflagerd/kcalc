// -*- c-basic-offset: 2 -*-
/* This file is part of the KDE libraries
    Copyright (C) 2005 Klaus Niederkrueger <kniederk@math.uni-koeln.de>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/
#ifndef _KNUMBER_H
#define _KNUMBER_H

#include <gmp.h>

#include <kdelibs_export.h>

#include "knumber_priv.h"

class QString;

/**
  *
  * KNumber provides access to arbitrary precision numbers from within
  * KDE.
  *
  * KNumber is base on the GMP (GNU Multiprecision) library and
  * provides transparent support to integer, fractional and floating
  * point number. It also includes methods for converting the numbers
  * to QStrings for output, and to read QStrings to obtain a KNumber.
  *
  * @author Klaus Niederkrueger <kniederk@math.uni-koeln.de>
  * @short class that provides arbitrary prcision numbers
  */
class KDE_EXPORT KNumber
{
 public:
  static KNumber const Zero;
  static KNumber const One;
  static KNumber const MinusOne;
  static KNumber const Pi;

  enum NumType {SpecialType, IntegerType, FractionType, FloatType};
  enum ErrorType {UndefinedNumber, Infinity, MinusInfinity};
  
  KNumber(signed int num = 1);

  KNumber(double num);

  KNumber(KNumber const & num);
  
  KNumber(QString const & num);
  
  ~KNumber()
  {
    delete _num;
  }
  
  KNumber const & operator=(KNumber const & num);

  NumType type(void) const;

  QString const toQString(int prec = -1) const;
  

  KNumber const abs(void) const;
  KNumber const sqrt(void) const;
  KNumber const cbrt(void) const;
  KNumber const integerPart(void) const;

  KNumber const operator+(KNumber const & arg2) const;
  KNumber const operator -(void) const;
  KNumber const operator-(KNumber const & arg2) const;
  KNumber const operator*(KNumber const & arg2) const;
  KNumber const operator/(KNumber const & arg2) const;
  KNumber const operator%(KNumber const & arg2) const;

  KNumber const operator&(KNumber const & arg2) const;
  KNumber const operator|(KNumber const & arg2) const;
  KNumber const operator<<(KNumber const & arg2) const;
  KNumber const operator>>(KNumber const & arg2) const;

  operator bool(void) const;

  bool const operator==(KNumber const & arg2) const
  { return (compare(arg2) == 0); }

  bool const operator!=(KNumber const & arg2) const
  { return (compare(arg2) != 0); }

  bool const operator>(KNumber const & arg2) const
  { return (compare(arg2) > 0); }

  bool const operator<(KNumber const & arg2) const
  { return (compare(arg2) < 0); }

  bool const operator>=(KNumber const & arg2) const
  { return (compare(arg2) >= 0); }

  bool const operator<=(KNumber const & arg2) const
  { return (compare(arg2) <= 0); }

  KNumber & operator +=(KNumber const &arg);
  KNumber & operator -=(KNumber const &arg);


  //KNumber const toFloat(void) const;
  
  
  
  
 private:
  void simplifyRational(void);
  int const compare(KNumber const & arg2) const;
  
  _knumber *_num;
  
};



#endif // _KNUMBER_H
