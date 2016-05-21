#include "checkboxdelegate.h"

QWidget *CheckBoxDelegate::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem & /* option */,
                                       const QModelIndex & /* index */) const
{
    QCheckBox *editor = new QCheckBox(parent);
    //editor->setMinimum(0);
    //editor->setMaximum(100);
    return editor;
}

void CheckBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();
    QCheckBox *spinBox = static_cast<QCheckBox*>(editor);
    //spinBox->setValue(value);
}

void CheckBoxDelegate::setModelData(QWidget *editor,
                                   QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QCheckBox *spinBox = static_cast<QCheckBox*>(editor);
    //spinBox->interpretText();
    //int value = spinBox->value();
    //model->setData(index, value, Qt::EditRole);
}

void CheckBoxDelegate::updateEditorGeometry(QWidget *editor,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
