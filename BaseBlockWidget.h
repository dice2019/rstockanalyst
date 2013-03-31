/************************************************************************/
/* �ļ����ƣ�BaseBlockWidget.h
/* ����ʱ�䣺2013-01-14 13:38
/*
/* ��    ��������ɫ��ͼ�ĳ��󣬼̳���CCoordXBaseWidget
/*           �����Ե�ʹ�ò�ͬ��ɫ������ʾ��Ʊ���������ƣ��Ӷ�����ͬ�������У�
/*           չ�ָ������Ϣ��
/************************************************************************/

#ifndef BASE_BLOCK_WIDGET_H
#define BASE_BLOCK_WIDGET_H
#include "CoordXBaseWidget.h"

class CBaseBlockWidget : public CCoordXBaseWidget
{
	Q_OBJECT
public:
	enum BlockMode
	{
		BlockCircle = 1,		//Բ��
		BlockRect,				//����
	};
	enum RSortType
	{
		SortByCode = 1,		//����Ʊ��������
		SortByIncrease,		//���Ƿ�����
		SortByTurnRatio,	//������������
		SortByVolumeRatio,	//����������
	};
public:
	CBaseBlockWidget(CBaseWidget* parent = 0, RWidgetType type = WidgetBasic);
	~CBaseBlockWidget(void);

public:
	//���ظ�K��ͼ��������Ϣ
	virtual bool loadPanelInfo(const QDomElement& eleWidget);
	//�����K��ͼ��������Ϣ
	virtual bool savePanelInfo(QDomDocument& doc,QDomElement& eleWidget);

	//��������
	virtual void updateData();

	//��������ʽ
	virtual void updateSortMode(){};
	
public:
	//ͨ������keyword��ȡ��Ҫ�ڼ��̾�������ʾ������
	virtual void getKeyWizData(const QString& keyword,QList<KeyWizData*>& listRet);
	//���̾��鴰��ȷ�Ϻ󴥷�
	virtual void keyWizEntered(KeyWizData* pData);

protected:
	//�麯���������ؼ����Զ���˵���
	virtual QMenu* getCustomMenu();

protected:
	//����ɫ��
	void drawColocBlock(QPainter& p,int iY,QVector<float>& vValue);

protected slots:
	void setColorMode(const QString& mode);					//������ɫģʽ

	void onSetColorMode();									//���������ɫģʽ
	void onSetBlockMode();									//���õ�ǰ����ʾģʽ
	void onSetBlockSize();									//����ɫ��Ĵ�С

	void onSetSortMode();									//�˵������õ�ǰ������ʽ

protected:
	void setSortMode(RSortType sort);						//���õ�ǰ������ʽ

protected:
	QMenu* m_pMenuColorMode;				//��ɫģʽ�˵�
	QMenu* m_pMenuBlockMode;				//��ʾģʽ�˵�
	QMenu* m_pMenuSortMode;					//����ʽ�˵�

	QString m_qsColorMode;					//��ǰ��ɫģʽ
protected:
	BlockMode m_typeBlock;					//block��ʾ��״
	int m_iCBHeight;						//����ɫ��ĸ߶�
	int m_iCBWidth;							//����ɫ��Ŀ���

	QRect m_rtClient;						//ʵ��ɫ���������

	RSortType m_sort;						//��ǰ������ʽ
	Qt::SortOrder m_sortOrder;				//��ǰ������ģʽ�����򣬽���
private:
	QList<RWidgetOpData> m_listSortOp;		//����ʽ�б�
};

#endif	//BASE_BLOCK_WIDGET_H