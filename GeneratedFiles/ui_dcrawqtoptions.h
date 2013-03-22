/********************************************************************************
** Form generated from reading UI file 'dcrawqtoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCRAWQTOPTIONS_H
#define UI_DCRAWQTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DcRawQTOptions
{
public:
    QGridLayout *gridLayout_8;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QRadioButton *rbNoWhiteBalance;
    QSpacerItem *horizontalSpacer_7;
    QRadioButton *rbCameraWhiteBalance;
    QSpacerItem *horizontalSpacer_8;
    QRadioButton *rbAverageGrayBox;
    QLineEdit *grayBoxX;
    QLineEdit *grayBoxY;
    QLineEdit *grayBoxW;
    QLineEdit *grayBoxH;
    QRadioButton *rbCustomWhiteBalance;
    QLineEdit *customR;
    QLineEdit *customG1;
    QLineEdit *customB;
    QLineEdit *customG2;
    QGroupBox *gbChromaticAberation;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leChromaticAberationR;
    QLineEdit *leChromaticAberationB;
    QGroupBox *gbUseGamma;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *leGammaG;
    QLineEdit *leGammaTS;
    QGroupBox *gbSaturationLevel;
    QHBoxLayout *horizontalLayout_7;
    QDoubleSpinBox *dsbSaturationLevel;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *gbDarknessLevel;
    QHBoxLayout *horizontalLayout_8;
    QDoubleSpinBox *dsbDarknessLevel;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *gbFlipImage;
    QGridLayout *gridLayout_7;
    QSpinBox *sbFlipImage;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *cbEmbeddedColorMatrix;
    QCheckBox *cbHalfSize;
    QCheckBox *cbInterpRGGB;
    QCheckBox *cbDontStretch;
    QCheckBox *cbWrite16Bit;
    QCheckBox *cbLinear16bit;
    QCheckBox *cbWriteTiff;
    QGroupBox *gbMedianFilter;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *sbMedianFilter;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *rbNoDocumentMode;
    QRadioButton *rbNoColorNoInterp;
    QRadioButton *rbNoScaling;
    QGroupBox *gbFixDeadPixels;
    QGridLayout *gridLayout_3;
    QLineEdit *leDeadPixelFile;
    QPushButton *pushButton;
    QGroupBox *gbDarkFrameFile;
    QGridLayout *gridLayout_4;
    QLineEdit *leDarkFrameFile;
    QPushButton *pushButton_2;
    QGroupBox *gbQuality;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *sbQuality;
    QSpacerItem *horizontalSpacer;
    QGroupBox *gbHighlightMode;
    QGridLayout *gridLayout_6;
    QSpinBox *sbHighlightMode;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout_9;
    QLabel *label_3;
    QGroupBox *groupBox_16;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lblCommandLine;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout;
    QRadioButton *rbNoBirghtness;
    QRadioButton *rbNoAutoBrighten;
    QRadioButton *rbBrightness;
    QSpacerItem *horizontalSpacer_3;
    QDoubleSpinBox *sbBrightness;
    QGroupBox *gbColorspace;
    QVBoxLayout *verticalLayout_5;
    QComboBox *cbColorspace;
    QGroupBox *gbDenoise;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *dsbdenoise;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *DcRawQTOptions)
    {
        if (DcRawQTOptions->objectName().isEmpty())
            DcRawQTOptions->setObjectName(QStringLiteral("DcRawQTOptions"));
        DcRawQTOptions->resize(930, 613);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DcRawQTOptions->sizePolicy().hasHeightForWidth());
        DcRawQTOptions->setSizePolicy(sizePolicy);
        DcRawQTOptions->setMinimumSize(QSize(773, 594));
        DcRawQTOptions->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Monospace"));
        font.setPointSize(7);
        DcRawQTOptions->setFont(font);
        gridLayout_8 = new QGridLayout(DcRawQTOptions);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        frame = new QFrame(DcRawQTOptions);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(755, 576));
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_5 = new QGroupBox(frame);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(8);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy1);
        groupBox_5->setMinimumSize(QSize(0, 0));
        groupBox_5->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        rbNoWhiteBalance = new QRadioButton(groupBox_5);
        rbNoWhiteBalance->setObjectName(QStringLiteral("rbNoWhiteBalance"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rbNoWhiteBalance->sizePolicy().hasHeightForWidth());
        rbNoWhiteBalance->setSizePolicy(sizePolicy2);
        rbNoWhiteBalance->setMinimumSize(QSize(50, 18));
        rbNoWhiteBalance->setChecked(true);

        gridLayout_2->addWidget(rbNoWhiteBalance, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 1, 1, 6);

        rbCameraWhiteBalance = new QRadioButton(groupBox_5);
        rbCameraWhiteBalance->setObjectName(QStringLiteral("rbCameraWhiteBalance"));
        sizePolicy2.setHeightForWidth(rbCameraWhiteBalance->sizePolicy().hasHeightForWidth());
        rbCameraWhiteBalance->setSizePolicy(sizePolicy2);
        rbCameraWhiteBalance->setMinimumSize(QSize(156, 10));
        rbCameraWhiteBalance->setChecked(false);

        gridLayout_2->addWidget(rbCameraWhiteBalance, 1, 0, 1, 2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 1, 2, 1, 5);

        rbAverageGrayBox = new QRadioButton(groupBox_5);
        rbAverageGrayBox->setObjectName(QStringLiteral("rbAverageGrayBox"));
        sizePolicy2.setHeightForWidth(rbAverageGrayBox->sizePolicy().hasHeightForWidth());
        rbAverageGrayBox->setSizePolicy(sizePolicy2);
        rbAverageGrayBox->setLayoutDirection(Qt::LeftToRight);
        rbAverageGrayBox->setChecked(false);

        gridLayout_2->addWidget(rbAverageGrayBox, 2, 0, 1, 3);

        grayBoxX = new QLineEdit(groupBox_5);
        grayBoxX->setObjectName(QStringLiteral("grayBoxX"));
        grayBoxX->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(grayBoxX->sizePolicy().hasHeightForWidth());
        grayBoxX->setSizePolicy(sizePolicy3);
        grayBoxX->setMinimumSize(QSize(48, 20));

        gridLayout_2->addWidget(grayBoxX, 2, 3, 1, 1);

        grayBoxY = new QLineEdit(groupBox_5);
        grayBoxY->setObjectName(QStringLiteral("grayBoxY"));
        grayBoxY->setEnabled(false);
        sizePolicy3.setHeightForWidth(grayBoxY->sizePolicy().hasHeightForWidth());
        grayBoxY->setSizePolicy(sizePolicy3);
        grayBoxY->setMinimumSize(QSize(48, 20));

        gridLayout_2->addWidget(grayBoxY, 2, 4, 1, 1);

        grayBoxW = new QLineEdit(groupBox_5);
        grayBoxW->setObjectName(QStringLiteral("grayBoxW"));
        grayBoxW->setEnabled(false);
        sizePolicy3.setHeightForWidth(grayBoxW->sizePolicy().hasHeightForWidth());
        grayBoxW->setSizePolicy(sizePolicy3);
        grayBoxW->setMinimumSize(QSize(48, 20));

        gridLayout_2->addWidget(grayBoxW, 2, 5, 1, 1);

        grayBoxH = new QLineEdit(groupBox_5);
        grayBoxH->setObjectName(QStringLiteral("grayBoxH"));
        grayBoxH->setEnabled(false);
        sizePolicy2.setHeightForWidth(grayBoxH->sizePolicy().hasHeightForWidth());
        grayBoxH->setSizePolicy(sizePolicy2);
        grayBoxH->setMinimumSize(QSize(48, 20));

        gridLayout_2->addWidget(grayBoxH, 2, 6, 1, 1);

        rbCustomWhiteBalance = new QRadioButton(groupBox_5);
        rbCustomWhiteBalance->setObjectName(QStringLiteral("rbCustomWhiteBalance"));
        sizePolicy2.setHeightForWidth(rbCustomWhiteBalance->sizePolicy().hasHeightForWidth());
        rbCustomWhiteBalance->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(rbCustomWhiteBalance, 3, 0, 1, 3);

        customR = new QLineEdit(groupBox_5);
        customR->setObjectName(QStringLiteral("customR"));
        customR->setEnabled(false);
        sizePolicy2.setHeightForWidth(customR->sizePolicy().hasHeightForWidth());
        customR->setSizePolicy(sizePolicy2);
        customR->setMinimumSize(QSize(48, 20));

        gridLayout_2->addWidget(customR, 3, 3, 1, 1);

        customG1 = new QLineEdit(groupBox_5);
        customG1->setObjectName(QStringLiteral("customG1"));
        customG1->setEnabled(false);
        sizePolicy2.setHeightForWidth(customG1->sizePolicy().hasHeightForWidth());
        customG1->setSizePolicy(sizePolicy2);
        customG1->setMinimumSize(QSize(48, 20));

        gridLayout_2->addWidget(customG1, 3, 4, 1, 1);

        customB = new QLineEdit(groupBox_5);
        customB->setObjectName(QStringLiteral("customB"));
        customB->setEnabled(false);
        sizePolicy2.setHeightForWidth(customB->sizePolicy().hasHeightForWidth());
        customB->setSizePolicy(sizePolicy2);
        customB->setMinimumSize(QSize(48, 20));

        gridLayout_2->addWidget(customB, 3, 5, 1, 1);

        customG2 = new QLineEdit(groupBox_5);
        customG2->setObjectName(QStringLiteral("customG2"));
        customG2->setEnabled(false);
        sizePolicy2.setHeightForWidth(customG2->sizePolicy().hasHeightForWidth());
        customG2->setSizePolicy(sizePolicy2);
        customG2->setMinimumSize(QSize(48, 20));

        gridLayout_2->addWidget(customG2, 3, 6, 1, 1);


        gridLayout_5->addWidget(groupBox_5, 0, 0, 2, 4);

        gbChromaticAberation = new QGroupBox(frame);
        gbChromaticAberation->setObjectName(QStringLiteral("gbChromaticAberation"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(4);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(gbChromaticAberation->sizePolicy().hasHeightForWidth());
        gbChromaticAberation->setSizePolicy(sizePolicy4);
        gbChromaticAberation->setMinimumSize(QSize(0, 0));
        gbChromaticAberation->setMaximumSize(QSize(16777215, 16777215));
        gbChromaticAberation->setCheckable(true);
        gbChromaticAberation->setChecked(false);
        horizontalLayout = new QHBoxLayout(gbChromaticAberation);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        leChromaticAberationR = new QLineEdit(gbChromaticAberation);
        leChromaticAberationR->setObjectName(QStringLiteral("leChromaticAberationR"));
        sizePolicy2.setHeightForWidth(leChromaticAberationR->sizePolicy().hasHeightForWidth());
        leChromaticAberationR->setSizePolicy(sizePolicy2);
        leChromaticAberationR->setMinimumSize(QSize(131, 20));

        horizontalLayout->addWidget(leChromaticAberationR);

        leChromaticAberationB = new QLineEdit(gbChromaticAberation);
        leChromaticAberationB->setObjectName(QStringLiteral("leChromaticAberationB"));
        sizePolicy2.setHeightForWidth(leChromaticAberationB->sizePolicy().hasHeightForWidth());
        leChromaticAberationB->setSizePolicy(sizePolicy2);
        leChromaticAberationB->setMinimumSize(QSize(131, 20));

        horizontalLayout->addWidget(leChromaticAberationB);


        gridLayout_5->addWidget(gbChromaticAberation, 0, 4, 1, 2);

        gbUseGamma = new QGroupBox(frame);
        gbUseGamma->setObjectName(QStringLiteral("gbUseGamma"));
        sizePolicy4.setHeightForWidth(gbUseGamma->sizePolicy().hasHeightForWidth());
        gbUseGamma->setSizePolicy(sizePolicy4);
        gbUseGamma->setMinimumSize(QSize(0, 0));
        gbUseGamma->setCheckable(true);
        gbUseGamma->setChecked(false);
        horizontalLayout_3 = new QHBoxLayout(gbUseGamma);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        leGammaG = new QLineEdit(gbUseGamma);
        leGammaG->setObjectName(QStringLiteral("leGammaG"));
        sizePolicy2.setHeightForWidth(leGammaG->sizePolicy().hasHeightForWidth());
        leGammaG->setSizePolicy(sizePolicy2);
        leGammaG->setMinimumSize(QSize(131, 20));

        horizontalLayout_3->addWidget(leGammaG);

        leGammaTS = new QLineEdit(gbUseGamma);
        leGammaTS->setObjectName(QStringLiteral("leGammaTS"));
        sizePolicy2.setHeightForWidth(leGammaTS->sizePolicy().hasHeightForWidth());
        leGammaTS->setSizePolicy(sizePolicy2);
        leGammaTS->setMinimumSize(QSize(131, 20));

        horizontalLayout_3->addWidget(leGammaTS);


        gridLayout_5->addWidget(gbUseGamma, 1, 4, 1, 2);

        gbSaturationLevel = new QGroupBox(frame);
        gbSaturationLevel->setObjectName(QStringLiteral("gbSaturationLevel"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(3);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(gbSaturationLevel->sizePolicy().hasHeightForWidth());
        gbSaturationLevel->setSizePolicy(sizePolicy5);
        gbSaturationLevel->setMinimumSize(QSize(0, 0));
        gbSaturationLevel->setCheckable(true);
        gbSaturationLevel->setChecked(false);
        horizontalLayout_7 = new QHBoxLayout(gbSaturationLevel);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        dsbSaturationLevel = new QDoubleSpinBox(gbSaturationLevel);
        dsbSaturationLevel->setObjectName(QStringLiteral("dsbSaturationLevel"));
        sizePolicy2.setHeightForWidth(dsbSaturationLevel->sizePolicy().hasHeightForWidth());
        dsbSaturationLevel->setSizePolicy(sizePolicy2);
        dsbSaturationLevel->setMinimumSize(QSize(112, 20));
        dsbSaturationLevel->setMaximum(100000);

        horizontalLayout_7->addWidget(dsbSaturationLevel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        gridLayout_5->addWidget(gbSaturationLevel, 2, 0, 1, 1);

        gbDarknessLevel = new QGroupBox(frame);
        gbDarknessLevel->setObjectName(QStringLiteral("gbDarknessLevel"));
        sizePolicy5.setHeightForWidth(gbDarknessLevel->sizePolicy().hasHeightForWidth());
        gbDarknessLevel->setSizePolicy(sizePolicy5);
        gbDarknessLevel->setMinimumSize(QSize(0, 0));
        gbDarknessLevel->setCheckable(true);
        gbDarknessLevel->setChecked(false);
        horizontalLayout_8 = new QHBoxLayout(gbDarknessLevel);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        dsbDarknessLevel = new QDoubleSpinBox(gbDarknessLevel);
        dsbDarknessLevel->setObjectName(QStringLiteral("dsbDarknessLevel"));
        sizePolicy2.setHeightForWidth(dsbDarknessLevel->sizePolicy().hasHeightForWidth());
        dsbDarknessLevel->setSizePolicy(sizePolicy2);
        dsbDarknessLevel->setMinimumSize(QSize(105, 20));
        dsbDarknessLevel->setMaximum(100000);

        horizontalLayout_8->addWidget(dsbDarknessLevel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        gridLayout_5->addWidget(gbDarknessLevel, 2, 1, 1, 2);

        gbFlipImage = new QGroupBox(frame);
        gbFlipImage->setObjectName(QStringLiteral("gbFlipImage"));
        sizePolicy5.setHeightForWidth(gbFlipImage->sizePolicy().hasHeightForWidth());
        gbFlipImage->setSizePolicy(sizePolicy5);
        gbFlipImage->setMinimumSize(QSize(0, 0));
        gbFlipImage->setCheckable(true);
        gbFlipImage->setChecked(false);
        gridLayout_7 = new QGridLayout(gbFlipImage);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        sbFlipImage = new QSpinBox(gbFlipImage);
        sbFlipImage->setObjectName(QStringLiteral("sbFlipImage"));
        sizePolicy2.setHeightForWidth(sbFlipImage->sizePolicy().hasHeightForWidth());
        sbFlipImage->setSizePolicy(sizePolicy2);
        sbFlipImage->setMinimumSize(QSize(69, 20));
        sbFlipImage->setMaximum(7);

        gridLayout_7->addWidget(sbFlipImage, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_5->addWidget(gbFlipImage, 2, 3, 2, 1);

        groupBox_8 = new QGroupBox(frame);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        sizePolicy5.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy5);
        groupBox_8->setMinimumSize(QSize(0, 0));
        verticalLayout_6 = new QVBoxLayout(groupBox_8);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        cbEmbeddedColorMatrix = new QCheckBox(groupBox_8);
        cbEmbeddedColorMatrix->setObjectName(QStringLiteral("cbEmbeddedColorMatrix"));
        sizePolicy2.setHeightForWidth(cbEmbeddedColorMatrix->sizePolicy().hasHeightForWidth());
        cbEmbeddedColorMatrix->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(cbEmbeddedColorMatrix);

        cbHalfSize = new QCheckBox(groupBox_8);
        cbHalfSize->setObjectName(QStringLiteral("cbHalfSize"));
        sizePolicy2.setHeightForWidth(cbHalfSize->sizePolicy().hasHeightForWidth());
        cbHalfSize->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(cbHalfSize);

        cbInterpRGGB = new QCheckBox(groupBox_8);
        cbInterpRGGB->setObjectName(QStringLiteral("cbInterpRGGB"));
        sizePolicy2.setHeightForWidth(cbInterpRGGB->sizePolicy().hasHeightForWidth());
        cbInterpRGGB->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(cbInterpRGGB);

        cbDontStretch = new QCheckBox(groupBox_8);
        cbDontStretch->setObjectName(QStringLiteral("cbDontStretch"));
        sizePolicy2.setHeightForWidth(cbDontStretch->sizePolicy().hasHeightForWidth());
        cbDontStretch->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(cbDontStretch);

        cbWrite16Bit = new QCheckBox(groupBox_8);
        cbWrite16Bit->setObjectName(QStringLiteral("cbWrite16Bit"));
        sizePolicy2.setHeightForWidth(cbWrite16Bit->sizePolicy().hasHeightForWidth());
        cbWrite16Bit->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(cbWrite16Bit);

        cbLinear16bit = new QCheckBox(groupBox_8);
        cbLinear16bit->setObjectName(QStringLiteral("cbLinear16bit"));
        sizePolicy2.setHeightForWidth(cbLinear16bit->sizePolicy().hasHeightForWidth());
        cbLinear16bit->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(cbLinear16bit);

        cbWriteTiff = new QCheckBox(groupBox_8);
        cbWriteTiff->setObjectName(QStringLiteral("cbWriteTiff"));
        sizePolicy2.setHeightForWidth(cbWriteTiff->sizePolicy().hasHeightForWidth());
        cbWriteTiff->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(cbWriteTiff);


        gridLayout_5->addWidget(groupBox_8, 2, 5, 3, 1);

        gbMedianFilter = new QGroupBox(frame);
        gbMedianFilter->setObjectName(QStringLiteral("gbMedianFilter"));
        sizePolicy5.setHeightForWidth(gbMedianFilter->sizePolicy().hasHeightForWidth());
        gbMedianFilter->setSizePolicy(sizePolicy5);
        gbMedianFilter->setMinimumSize(QSize(0, 0));
        gbMedianFilter->setCheckable(true);
        gbMedianFilter->setChecked(false);
        horizontalLayout_5 = new QHBoxLayout(gbMedianFilter);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        sbMedianFilter = new QSpinBox(gbMedianFilter);
        sbMedianFilter->setObjectName(QStringLiteral("sbMedianFilter"));
        sizePolicy.setHeightForWidth(sbMedianFilter->sizePolicy().hasHeightForWidth());
        sbMedianFilter->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(sbMedianFilter);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        gridLayout_5->addWidget(gbMedianFilter, 3, 1, 1, 2);

        groupBox_9 = new QGroupBox(frame);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(4);
        sizePolicy6.setVerticalStretch(2);
        sizePolicy6.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy6);
        groupBox_9->setMinimumSize(QSize(0, 0));
        verticalLayout_4 = new QVBoxLayout(groupBox_9);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        rbNoDocumentMode = new QRadioButton(groupBox_9);
        rbNoDocumentMode->setObjectName(QStringLiteral("rbNoDocumentMode"));
        sizePolicy.setHeightForWidth(rbNoDocumentMode->sizePolicy().hasHeightForWidth());
        rbNoDocumentMode->setSizePolicy(sizePolicy);
        rbNoDocumentMode->setChecked(true);

        verticalLayout_4->addWidget(rbNoDocumentMode);

        rbNoColorNoInterp = new QRadioButton(groupBox_9);
        rbNoColorNoInterp->setObjectName(QStringLiteral("rbNoColorNoInterp"));
        sizePolicy.setHeightForWidth(rbNoColorNoInterp->sizePolicy().hasHeightForWidth());
        rbNoColorNoInterp->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(rbNoColorNoInterp);

        rbNoScaling = new QRadioButton(groupBox_9);
        rbNoScaling->setObjectName(QStringLiteral("rbNoScaling"));
        sizePolicy.setHeightForWidth(rbNoScaling->sizePolicy().hasHeightForWidth());
        rbNoScaling->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(rbNoScaling);


        gridLayout_5->addWidget(groupBox_9, 4, 2, 1, 3);

        gbFixDeadPixels = new QGroupBox(frame);
        gbFixDeadPixels->setObjectName(QStringLiteral("gbFixDeadPixels"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(6);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(gbFixDeadPixels->sizePolicy().hasHeightForWidth());
        gbFixDeadPixels->setSizePolicy(sizePolicy7);
        gbFixDeadPixels->setMinimumSize(QSize(0, 0));
        gbFixDeadPixels->setCheckable(true);
        gbFixDeadPixels->setChecked(false);
        gridLayout_3 = new QGridLayout(gbFixDeadPixels);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        leDeadPixelFile = new QLineEdit(gbFixDeadPixels);
        leDeadPixelFile->setObjectName(QStringLiteral("leDeadPixelFile"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(2);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(leDeadPixelFile->sizePolicy().hasHeightForWidth());
        leDeadPixelFile->setSizePolicy(sizePolicy8);
        leDeadPixelFile->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(leDeadPixelFile, 0, 0, 1, 1);

        pushButton = new QPushButton(gbFixDeadPixels);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy9);

        gridLayout_3->addWidget(pushButton, 0, 1, 1, 1);


        gridLayout_5->addWidget(gbFixDeadPixels, 5, 0, 1, 3);

        gbDarkFrameFile = new QGroupBox(frame);
        gbDarkFrameFile->setObjectName(QStringLiteral("gbDarkFrameFile"));
        sizePolicy7.setHeightForWidth(gbDarkFrameFile->sizePolicy().hasHeightForWidth());
        gbDarkFrameFile->setSizePolicy(sizePolicy7);
        gbDarkFrameFile->setMinimumSize(QSize(0, 0));
        gbDarkFrameFile->setCheckable(true);
        gbDarkFrameFile->setChecked(false);
        gridLayout_4 = new QGridLayout(gbDarkFrameFile);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        leDarkFrameFile = new QLineEdit(gbDarkFrameFile);
        leDarkFrameFile->setObjectName(QStringLiteral("leDarkFrameFile"));
        sizePolicy8.setHeightForWidth(leDarkFrameFile->sizePolicy().hasHeightForWidth());
        leDarkFrameFile->setSizePolicy(sizePolicy8);
        leDarkFrameFile->setMinimumSize(QSize(0, 0));

        gridLayout_4->addWidget(leDarkFrameFile, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(gbDarkFrameFile);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy9.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy9);

        gridLayout_4->addWidget(pushButton_2, 1, 1, 1, 1);


        gridLayout_5->addWidget(gbDarkFrameFile, 5, 3, 1, 3);

        gbQuality = new QGroupBox(frame);
        gbQuality->setObjectName(QStringLiteral("gbQuality"));
        sizePolicy7.setHeightForWidth(gbQuality->sizePolicy().hasHeightForWidth());
        gbQuality->setSizePolicy(sizePolicy7);
        gbQuality->setMinimumSize(QSize(0, 0));
        gbQuality->setCheckable(true);
        gbQuality->setChecked(false);
        horizontalLayout_4 = new QHBoxLayout(gbQuality);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        sbQuality = new QSpinBox(gbQuality);
        sbQuality->setObjectName(QStringLiteral("sbQuality"));
        sizePolicy9.setHeightForWidth(sbQuality->sizePolicy().hasHeightForWidth());
        sbQuality->setSizePolicy(sizePolicy9);
        sbQuality->setMinimumSize(QSize(0, 0));
        sbQuality->setMaximum(3);

        horizontalLayout_4->addWidget(sbQuality);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout_5->addWidget(gbQuality, 6, 0, 1, 3);

        gbHighlightMode = new QGroupBox(frame);
        gbHighlightMode->setObjectName(QStringLiteral("gbHighlightMode"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy10.setHorizontalStretch(6);
        sizePolicy10.setVerticalStretch(1);
        sizePolicy10.setHeightForWidth(gbHighlightMode->sizePolicy().hasHeightForWidth());
        gbHighlightMode->setSizePolicy(sizePolicy10);
        gbHighlightMode->setMinimumSize(QSize(0, 0));
        gbHighlightMode->setCheckable(true);
        gbHighlightMode->setChecked(false);
        gridLayout_6 = new QGridLayout(gbHighlightMode);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        sbHighlightMode = new QSpinBox(gbHighlightMode);
        sbHighlightMode->setObjectName(QStringLiteral("sbHighlightMode"));
        sizePolicy9.setHeightForWidth(sbHighlightMode->sizePolicy().hasHeightForWidth());
        sbHighlightMode->setSizePolicy(sizePolicy9);
        sbHighlightMode->setMinimumSize(QSize(0, 0));
        sbHighlightMode->setMaximum(9);

        gridLayout_6->addWidget(sbHighlightMode, 0, 0, 1, 1);

        label = new QLabel(gbHighlightMode);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_6->addWidget(label, 0, 1, 1, 1);


        gridLayout_5->addWidget(gbHighlightMode, 6, 3, 1, 3);

        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy10.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy10);
        widget->setMinimumSize(QSize(355, 51));
        gridLayout_9 = new QGridLayout(widget);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy9.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy9);
        label_3->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setFrameShape(QFrame::StyledPanel);

        gridLayout_9->addWidget(label_3, 0, 0, 1, 1);


        gridLayout_5->addWidget(widget, 7, 0, 1, 3);

        groupBox_16 = new QGroupBox(frame);
        groupBox_16->setObjectName(QStringLiteral("groupBox_16"));
        sizePolicy10.setHeightForWidth(groupBox_16->sizePolicy().hasHeightForWidth());
        groupBox_16->setSizePolicy(sizePolicy10);
        groupBox_16->setMinimumSize(QSize(0, 0));
        horizontalLayout_6 = new QHBoxLayout(groupBox_16);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        lblCommandLine = new QLabel(groupBox_16);
        lblCommandLine->setObjectName(QStringLiteral("lblCommandLine"));
        sizePolicy9.setHeightForWidth(lblCommandLine->sizePolicy().hasHeightForWidth());
        lblCommandLine->setSizePolicy(sizePolicy9);
        lblCommandLine->setMinimumSize(QSize(0, 0));

        horizontalLayout_6->addWidget(lblCommandLine);


        gridLayout_5->addWidget(groupBox_16, 7, 3, 1, 3);

        groupBox_12 = new QGroupBox(frame);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        QSizePolicy sizePolicy11(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy11.setHorizontalStretch(4);
        sizePolicy11.setVerticalStretch(4);
        sizePolicy11.setHeightForWidth(groupBox_12->sizePolicy().hasHeightForWidth());
        groupBox_12->setSizePolicy(sizePolicy11);
        groupBox_12->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(groupBox_12);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rbNoBirghtness = new QRadioButton(groupBox_12);
        rbNoBirghtness->setObjectName(QStringLiteral("rbNoBirghtness"));
        sizePolicy.setHeightForWidth(rbNoBirghtness->sizePolicy().hasHeightForWidth());
        rbNoBirghtness->setSizePolicy(sizePolicy);
        rbNoBirghtness->setChecked(true);

        gridLayout->addWidget(rbNoBirghtness, 0, 0, 1, 1);

        rbNoAutoBrighten = new QRadioButton(groupBox_12);
        rbNoAutoBrighten->setObjectName(QStringLiteral("rbNoAutoBrighten"));
        sizePolicy.setHeightForWidth(rbNoAutoBrighten->sizePolicy().hasHeightForWidth());
        rbNoAutoBrighten->setSizePolicy(sizePolicy);

        gridLayout->addWidget(rbNoAutoBrighten, 1, 0, 1, 2);

        rbBrightness = new QRadioButton(groupBox_12);
        rbBrightness->setObjectName(QStringLiteral("rbBrightness"));
        sizePolicy.setHeightForWidth(rbBrightness->sizePolicy().hasHeightForWidth());
        rbBrightness->setSizePolicy(sizePolicy);

        gridLayout->addWidget(rbBrightness, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        sbBrightness = new QDoubleSpinBox(groupBox_12);
        sbBrightness->setObjectName(QStringLiteral("sbBrightness"));
        sbBrightness->setEnabled(false);
        sizePolicy.setHeightForWidth(sbBrightness->sizePolicy().hasHeightForWidth());
        sbBrightness->setSizePolicy(sizePolicy);
        sbBrightness->setMinimumSize(QSize(0, 0));
        sbBrightness->setMaximum(99999);

        gridLayout->addWidget(sbBrightness, 2, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_12, 4, 0, 1, 2);

        gbColorspace = new QGroupBox(frame);
        gbColorspace->setObjectName(QStringLiteral("gbColorspace"));
        sizePolicy5.setHeightForWidth(gbColorspace->sizePolicy().hasHeightForWidth());
        gbColorspace->setSizePolicy(sizePolicy5);
        gbColorspace->setMinimumSize(QSize(0, 0));
        gbColorspace->setCheckable(true);
        gbColorspace->setChecked(false);
        verticalLayout_5 = new QVBoxLayout(gbColorspace);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        cbColorspace = new QComboBox(gbColorspace);
        cbColorspace->setObjectName(QStringLiteral("cbColorspace"));
        sizePolicy.setHeightForWidth(cbColorspace->sizePolicy().hasHeightForWidth());
        cbColorspace->setSizePolicy(sizePolicy);
        cbColorspace->setEditable(false);

        verticalLayout_5->addWidget(cbColorspace);


        gridLayout_5->addWidget(gbColorspace, 3, 0, 1, 1);

        gbDenoise = new QGroupBox(frame);
        gbDenoise->setObjectName(QStringLiteral("gbDenoise"));
        gbDenoise->setCheckable(true);
        gbDenoise->setChecked(false);
        verticalLayout = new QVBoxLayout(gbDenoise);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        dsbdenoise = new QDoubleSpinBox(gbDenoise);
        dsbdenoise->setObjectName(QStringLiteral("dsbdenoise"));
        dsbdenoise->setMaximum(999999);

        verticalLayout->addWidget(dsbdenoise);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        gridLayout_5->addWidget(gbDenoise, 2, 4, 2, 1);


        gridLayout_8->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(DcRawQTOptions);
        QObject::connect(rbAverageGrayBox, SIGNAL(toggled(bool)), grayBoxX, SLOT(setEnabled(bool)));
        QObject::connect(rbAverageGrayBox, SIGNAL(toggled(bool)), grayBoxY, SLOT(setEnabled(bool)));
        QObject::connect(rbAverageGrayBox, SIGNAL(toggled(bool)), grayBoxW, SLOT(setEnabled(bool)));
        QObject::connect(rbAverageGrayBox, SIGNAL(toggled(bool)), grayBoxH, SLOT(setEnabled(bool)));
        QObject::connect(rbCustomWhiteBalance, SIGNAL(toggled(bool)), customR, SLOT(setEnabled(bool)));
        QObject::connect(rbCustomWhiteBalance, SIGNAL(toggled(bool)), customG1, SLOT(setEnabled(bool)));
        QObject::connect(rbCustomWhiteBalance, SIGNAL(toggled(bool)), customB, SLOT(setEnabled(bool)));
        QObject::connect(rbCustomWhiteBalance, SIGNAL(toggled(bool)), customG2, SLOT(setEnabled(bool)));
        QObject::connect(rbBrightness, SIGNAL(toggled(bool)), sbBrightness, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(DcRawQTOptions);
    } // setupUi

    void retranslateUi(QWidget *DcRawQTOptions)
    {
        DcRawQTOptions->setWindowTitle(QApplication::translate("DcRawQTOptions", "Form", 0));
        groupBox_5->setTitle(QApplication::translate("DcRawQTOptions", "White Balance", 0));
        rbNoWhiteBalance->setText(QApplication::translate("DcRawQTOptions", "None", 0));
        rbCameraWhiteBalance->setText(QApplication::translate("DcRawQTOptions", "Camera White Balance (-w)", 0));
        rbAverageGrayBox->setText(QApplication::translate("DcRawQTOptions", "Average Gray Box (-A <x y w h>)", 0));
        rbCustomWhiteBalance->setText(QApplication::translate("DcRawQTOptions", "Custom White Balance (-r <r g b g>)", 0));
        customR->setInputMask(QString());
        customG1->setInputMask(QString());
        customB->setInputMask(QString());
        customG2->setInputMask(QString());
        gbChromaticAberation->setTitle(QApplication::translate("DcRawQTOptions", "Correct Chromatic Aberation (-C <r b>)", 0));
        gbUseGamma->setTitle(QApplication::translate("DcRawQTOptions", "Use Gamma (-g <p ts>", 0));
        gbSaturationLevel->setTitle(QApplication::translate("DcRawQTOptions", "Saturation Level (-S <num>)", 0));
        gbDarknessLevel->setTitle(QApplication::translate("DcRawQTOptions", "Darkness Level (-k <num>)", 0));
        gbFlipImage->setTitle(QApplication::translate("DcRawQTOptions", "Flip Image (-t [0-7])", 0));
        groupBox_8->setTitle(QString());
        cbEmbeddedColorMatrix->setText(QApplication::translate("DcRawQTOptions", "Use Embedded Color Matrix (+M/-M)", 0));
        cbHalfSize->setText(QApplication::translate("DcRawQTOptions", "Half Size Color Image (-h)", 0));
        cbInterpRGGB->setText(QApplication::translate("DcRawQTOptions", "Interpolate RGGB as four colors (-f)", 0));
        cbDontStretch->setText(QApplication::translate("DcRawQTOptions", "Don't stretch or rotate (-j)", 0));
        cbWrite16Bit->setText(QApplication::translate("DcRawQTOptions", "Write 16-bit instead of 8-bit (-6)", 0));
        cbLinear16bit->setText(QApplication::translate("DcRawQTOptions", "Linear 16-bit, same as -6 -W -g 1 1 (-4)", 0));
        cbWriteTiff->setText(QApplication::translate("DcRawQTOptions", "Write Tiff instead of PPM (-T)", 0));
        gbMedianFilter->setTitle(QApplication::translate("DcRawQTOptions", "Median Filter (-m <num>)", 0));
        groupBox_9->setTitle(QApplication::translate("DcRawQTOptions", "Document Mode", 0));
        rbNoDocumentMode->setText(QApplication::translate("DcRawQTOptions", "None", 0));
        rbNoColorNoInterp->setText(QApplication::translate("DcRawQTOptions", "No Color, No interpolation (-d)", 0));
        rbNoScaling->setText(QApplication::translate("DcRawQTOptions", "No Scaling (-D)", 0));
        gbFixDeadPixels->setTitle(QApplication::translate("DcRawQTOptions", "Fix Dead Pixels (-P <filename>)", 0));
        pushButton->setText(QApplication::translate("DcRawQTOptions", "Browse...", 0));
        gbDarkFrameFile->setTitle(QApplication::translate("DcRawQTOptions", "Subtract Dark Frame (-K <filename>)", 0));
        pushButton_2->setText(QApplication::translate("DcRawQTOptions", "Browse...", 0));
        gbQuality->setTitle(QApplication::translate("DcRawQTOptions", "Set interpolation quality (-q [0-3])", 0));
        gbHighlightMode->setTitle(QApplication::translate("DcRawQTOptions", "Set Hightlight Mode (-H [0-9])", 0));
        label->setText(QApplication::translate("DcRawQTOptions", " ( 0 = clip, 1 = unclip, 2 = blend,  3+ = rebuild) ", 0));
        label_3->setText(QApplication::translate("DcRawQTOptions", "DcRawQT Options", 0));
        groupBox_16->setTitle(QApplication::translate("DcRawQTOptions", "Command-Line", 0));
        lblCommandLine->setText(QApplication::translate("DcRawQTOptions", "TextLabel", 0));
        groupBox_12->setTitle(QApplication::translate("DcRawQTOptions", "Brightness", 0));
        rbNoBirghtness->setText(QApplication::translate("DcRawQTOptions", "None", 0));
        rbNoAutoBrighten->setText(QApplication::translate("DcRawQTOptions", "Don't automatically brighten the image (-W)", 0));
        rbBrightness->setText(QApplication::translate("DcRawQTOptions", "Adjust Brightness(-b <num>)", 0));
        gbColorspace->setTitle(QApplication::translate("DcRawQTOptions", "Colorspace (-o [0-5])", 0));
        cbColorspace->clear();
        cbColorspace->insertItems(0, QStringList()
         << QApplication::translate("DcRawQTOptions", "raw", 0)
         << QApplication::translate("DcRawQTOptions", "sRGB", 0)
         << QApplication::translate("DcRawQTOptions", "Adobe", 0)
         << QApplication::translate("DcRawQTOptions", "Wide", 0)
         << QApplication::translate("DcRawQTOptions", "ProPhoto", 0)
         << QApplication::translate("DcRawQTOptions", "XYZ", 0)
        );
        gbDenoise->setTitle(QApplication::translate("DcRawQTOptions", "Denoise (-n <num>)", 0));
    } // retranslateUi

};

namespace Ui {
    class DcRawQTOptions: public Ui_DcRawQTOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCRAWQTOPTIONS_H
