// Copyright (c) 2022 The Tutela developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef Tutela_ADDRESSHOLDER_H
#define Tutela_ADDRESSHOLDER_H

#include <QWidget>
#include <QColor>
#include "qt/tutela/myaddressrow.h"
#include "qt/tutela/furlistrow.h"
#include "guiutil.h"


class AddressHolder : public FurListRow<QWidget*>
{
public:
    AddressHolder();

    explicit AddressHolder(bool _isLightTheme) : FurListRow(), isLightTheme(_isLightTheme){}

    MyAddressRow* createHolder(int pos) override{
        if (!cachedRow) cachedRow = new MyAddressRow();
        return cachedRow;
    }

    void init(QWidget* holder,const QModelIndex &index, bool isHovered, bool isSelected) const override;

    QColor rectColor(bool isHovered, bool isSelected) override;

    ~AddressHolder() override {
        if (cachedRow)
            delete cachedRow;
    }

    bool isLightTheme;
    MyAddressRow* cachedRow = nullptr;
};


#endif //Tutela_ADDRESSHOLDER_H
