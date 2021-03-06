/*
 * AccountItem.h
 *
 *  Created on: May 27, 2013
 *      Author: CongDanh
 */

#ifndef ACCOUNTITEM_H_
#define ACCOUNTITEM_H_

#include <stdint.h>
#include <qt4/QtCore/QObject>
#include <qt4/QtCore/qmetatype.h>

class AccountItem: public QObject {
	Q_OBJECT
	Q_PROPERTY(int id READ id CONSTANT)
	Q_PROPERTY(QString code READ code NOTIFY codeChanged FINAL)
	Q_PROPERTY(int type READ type CONSTANT)
	Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged FINAL)
	Q_PROPERTY(QString email READ email CONSTANT)
	Q_PROPERTY(bool next READ next CONSTANT)
public:
	AccountItem(QObject* parent = 0);
	AccountItem(const AccountItem&);
	AccountItem(int id, const QString& email, const QString& secret, int type, int counter, int digits = 6, QObject* parent = 0);
	virtual ~AccountItem();

	int id() const;
	QString email() const;
	QString code() const;
	int type() const;
	bool enabled() const;
	bool next();

	Q_SIGNALS:
	void codeChanged(const QString& code);
	void enabledChanged(int type);

private slots:
	void setEnabled(bool enabled = true);
private:
	inline void setCode(int code);
	int m_iId;
	int m_iType;
	int m_iCounter;
	int m_len;
	int m_iDigits;
	uint8_t* m_pSecret;
	bool m_iEnabled;
	QString m_code;
	QString m_email;
};

// Q_DECLARE_METATYPE( AccountItem* )
#endif /* ACCOUNTITEM_H_ */
