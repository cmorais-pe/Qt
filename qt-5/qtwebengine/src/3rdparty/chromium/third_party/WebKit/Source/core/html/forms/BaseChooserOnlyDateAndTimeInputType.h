/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef BaseChooserOnlyDateAndTimeInputType_h
#define BaseChooserOnlyDateAndTimeInputType_h

#if !ENABLE(INPUT_MULTIPLE_FIELDS_UI)
#include "core/html/forms/BaseClickableWithKeyInputType.h"
#include "core/html/forms/BaseDateAndTimeInputType.h"
#include "core/html/forms/DateTimeChooser.h"
#include "core/html/forms/DateTimeChooserClient.h"

namespace blink {

class BaseChooserOnlyDateAndTimeInputType : public BaseDateAndTimeInputType, public DateTimeChooserClient {
protected:
    BaseChooserOnlyDateAndTimeInputType(HTMLInputElement& element) : BaseDateAndTimeInputType(element) { }
    virtual ~BaseChooserOnlyDateAndTimeInputType();

private:
    void closeDateTimeChooser();

    // InputType functions:
    virtual void createShadowSubtree() override;
    virtual void closePopupView() override;
    virtual void setValue(const String&, bool valueChanged, TextFieldEventBehavior) override;
    virtual void handleDOMActivateEvent(Event*) override;
    virtual void handleKeydownEvent(KeyboardEvent*) override;
    virtual void handleKeypressEvent(KeyboardEvent*) override;
    virtual void handleKeyupEvent(KeyboardEvent*) override;
    virtual void accessKeyAction(bool sendMouseEvents) override;
    virtual void updateView() override;

    // DateTimeChooserClient functions:
    virtual Element& ownerElement() const override;
    virtual void didChooseValue(const String&) override;
    virtual void didChooseValue(double) override;
    virtual void didEndChooser() override;

    RefPtr<DateTimeChooser> m_dateTimeChooser;
};

}
#endif
#endif
