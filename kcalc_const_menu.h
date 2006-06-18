/*
    KCalc, a scientific calculator for the X window system using the
    Qt widget libraries, available at no cost at http://www.troll.no

    Copyright (C) 2004 Klaus Niederkruger

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#ifndef _KCALC_CONST_MENU_H
#define _KCALC_CONST_MENU_H

#include <QMenu>
#include <QString>

enum ConstantCategory {Mathematics = 1, Electromagnetic = 2, Nuclear = 4, Thermodynamics = 8, Gravitation = 16};

struct science_constant{
  QString label;
  const char * name;
  QString whatsthis;
  QString value;
  ConstantCategory category;
};

class KCalcConstMenu : public QMenu
{
Q_OBJECT 

 public:
  KCalcConstMenu(QWidget * parent = 0);
  KCalcConstMenu(QString const & title, QWidget * parent = 0);

  static const struct science_constant Constants[];

 private:
  void _init_all(void);

public slots:
  void slotPassActivate(int item)
  {
    emit activated(item);
  };
};

#endif  // _KCALC_CONST_MENU_H
