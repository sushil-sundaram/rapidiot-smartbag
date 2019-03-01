#include "callbacks.h"

//HEADER START

//HEADER END

void ATMO_Setup() {


}


ATMO_Status_t NFCOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t NFCOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(NFCOnOff, x), ATMO_PROPERTY(NFCOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t NFCOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t NFCOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t NFCOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t NFCOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t NFCOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(NFCOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(NFCOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(NFCOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(NFCOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(NFCOnOff, topLeftButtonEnabled), ATMO_PROPERTY(NFCOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(NFCOnOff, x);
    config.y = ATMO_PROPERTY(NFCOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(NFCOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(NFCOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(NFCOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(NFCOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(NFCOnOff, spanX);
	config.spanY = ATMO_PROPERTY(NFCOnOff, spanY);
    config.title = ATMO_PROPERTY(NFCOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(NFCOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(NFCOnOff, persist), ATMO_PROPERTY(NFCOnOff, differentStartup));
    ATMO_VARIABLE(NFCOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(NFCOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(NFCOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(NFCOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(NFCOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(NFCOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(NFCOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(NFCOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(NFCOnOff,pageHandle), 1, ATMO_ABILITY(NFCOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(NFCOnOff,pageHandle), 2, ATMO_ABILITY(NFCOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(NFCOnOff,pageHandle), 3, ATMO_ABILITY(NFCOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(NFCOnOff,pageHandle), ATMO_ABILITY(NFCOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(NFCOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t NFCOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(NFCOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t NFCOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(NFCOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t NFCOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t NFCOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t NFCOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t NFCOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t ThreadOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t ThreadOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(ThreadOnOff, x), ATMO_PROPERTY(ThreadOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t ThreadOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t ThreadOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t ThreadOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t ThreadOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t ThreadOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(ThreadOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(ThreadOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(ThreadOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(ThreadOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(ThreadOnOff, topLeftButtonEnabled), ATMO_PROPERTY(ThreadOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(ThreadOnOff, x);
    config.y = ATMO_PROPERTY(ThreadOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(ThreadOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(ThreadOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(ThreadOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(ThreadOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(ThreadOnOff, spanX);
	config.spanY = ATMO_PROPERTY(ThreadOnOff, spanY);
    config.title = ATMO_PROPERTY(ThreadOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(ThreadOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(ThreadOnOff, persist), ATMO_PROPERTY(ThreadOnOff, differentStartup));
    ATMO_VARIABLE(ThreadOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(ThreadOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(ThreadOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(ThreadOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(ThreadOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(ThreadOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(ThreadOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(ThreadOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(ThreadOnOff,pageHandle), 1, ATMO_ABILITY(ThreadOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(ThreadOnOff,pageHandle), 2, ATMO_ABILITY(ThreadOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(ThreadOnOff,pageHandle), 3, ATMO_ABILITY(ThreadOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(ThreadOnOff,pageHandle), ATMO_ABILITY(ThreadOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(ThreadOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t ThreadOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(ThreadOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t ThreadOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(ThreadOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t ThreadOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t ThreadOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t ThreadOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t ThreadOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t BluetoothOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t BluetoothOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(BluetoothOnOff, x), ATMO_PROPERTY(BluetoothOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t BluetoothOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t BluetoothOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BluetoothOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BluetoothOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BluetoothOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(BluetoothOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(BluetoothOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(BluetoothOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(BluetoothOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(BluetoothOnOff, topLeftButtonEnabled), ATMO_PROPERTY(BluetoothOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(BluetoothOnOff, x);
    config.y = ATMO_PROPERTY(BluetoothOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(BluetoothOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(BluetoothOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(BluetoothOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(BluetoothOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(BluetoothOnOff, spanX);
	config.spanY = ATMO_PROPERTY(BluetoothOnOff, spanY);
    config.title = ATMO_PROPERTY(BluetoothOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(BluetoothOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(BluetoothOnOff, persist), ATMO_PROPERTY(BluetoothOnOff, differentStartup));
    ATMO_VARIABLE(BluetoothOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(BluetoothOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(BluetoothOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(BluetoothOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(BluetoothOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(BluetoothOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(BluetoothOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(BluetoothOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(BluetoothOnOff,pageHandle), 1, ATMO_ABILITY(BluetoothOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(BluetoothOnOff,pageHandle), 2, ATMO_ABILITY(BluetoothOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(BluetoothOnOff,pageHandle), 3, ATMO_ABILITY(BluetoothOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(BluetoothOnOff,pageHandle), ATMO_ABILITY(BluetoothOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(BluetoothOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t BluetoothOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(BluetoothOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t BluetoothOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(BluetoothOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t BluetoothOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t BluetoothOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t BluetoothOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t BluetoothOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Buzzer_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Buzzer_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Buzzer, x), ATMO_PROPERTY(Buzzer, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Buzzer_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Buzzer_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Buzzer_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Buzzer_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Buzzer_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(Buzzer, pageHidden);
    config.textColor = ATMO_PROPERTY(Buzzer, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Buzzer, topRightButtonEnabled),
		ATMO_PROPERTY(Buzzer,bottomRightButtonEnabled), ATMO_PROPERTY(Buzzer, topLeftButtonEnabled), ATMO_PROPERTY(Buzzer, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Buzzer, x);
    config.y = ATMO_PROPERTY(Buzzer, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Buzzer, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Buzzer, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Buzzer, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Buzzer, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Buzzer, spanX);
	config.spanY = ATMO_PROPERTY(Buzzer, spanY);
    config.title = ATMO_PROPERTY(Buzzer, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Buzzer, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(Buzzer, persist), ATMO_PROPERTY(Buzzer, differentStartup));
    ATMO_VARIABLE(Buzzer, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(Buzzer,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(Buzzer, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(Buzzer, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(Buzzer, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(Buzzer, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(Buzzer, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(Buzzer, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(Buzzer,pageHandle), 1, ATMO_ABILITY(Buzzer, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(Buzzer,pageHandle), 2, ATMO_ABILITY(Buzzer, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(Buzzer,pageHandle), 3, ATMO_ABILITY(Buzzer, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Buzzer,pageHandle), ATMO_ABILITY(Buzzer, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(Buzzer, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t Buzzer_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(Buzzer,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t Buzzer_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(Buzzer,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t Buzzer_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t Buzzer_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t Buzzer_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Buzzer_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(AccelOnOff, x), ATMO_PROPERTY(AccelOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t AccelOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(AccelOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(AccelOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(AccelOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(AccelOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(AccelOnOff, topLeftButtonEnabled), ATMO_PROPERTY(AccelOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(AccelOnOff, x);
    config.y = ATMO_PROPERTY(AccelOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(AccelOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(AccelOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(AccelOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(AccelOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(AccelOnOff, spanX);
	config.spanY = ATMO_PROPERTY(AccelOnOff, spanY);
    config.title = ATMO_PROPERTY(AccelOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(AccelOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(AccelOnOff, persist), ATMO_PROPERTY(AccelOnOff, differentStartup));
    ATMO_VARIABLE(AccelOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(AccelOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(AccelOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(AccelOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(AccelOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(AccelOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(AccelOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(AccelOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(AccelOnOff,pageHandle), 1, ATMO_ABILITY(AccelOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(AccelOnOff,pageHandle), 2, ATMO_ABILITY(AccelOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(AccelOnOff,pageHandle), 3, ATMO_ABILITY(AccelOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(AccelOnOff,pageHandle), ATMO_ABILITY(AccelOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(AccelOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t AccelOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(AccelOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t AccelOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(AccelOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t AccelOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t AccelOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t AccelOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(GyroOnOff, x), ATMO_PROPERTY(GyroOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t GyroOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(GyroOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(GyroOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(GyroOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(GyroOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(GyroOnOff, topLeftButtonEnabled), ATMO_PROPERTY(GyroOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(GyroOnOff, x);
    config.y = ATMO_PROPERTY(GyroOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(GyroOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(GyroOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(GyroOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(GyroOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(GyroOnOff, spanX);
	config.spanY = ATMO_PROPERTY(GyroOnOff, spanY);
    config.title = ATMO_PROPERTY(GyroOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(GyroOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(GyroOnOff, persist), ATMO_PROPERTY(GyroOnOff, differentStartup));
    ATMO_VARIABLE(GyroOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(GyroOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(GyroOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(GyroOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(GyroOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(GyroOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(GyroOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(GyroOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(GyroOnOff,pageHandle), 1, ATMO_ABILITY(GyroOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(GyroOnOff,pageHandle), 2, ATMO_ABILITY(GyroOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(GyroOnOff,pageHandle), 3, ATMO_ABILITY(GyroOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(GyroOnOff,pageHandle), ATMO_ABILITY(GyroOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(GyroOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t GyroOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(GyroOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t GyroOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(GyroOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t GyroOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t GyroOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t GyroOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t PressureOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t PressureOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(PressureOnOff, x), ATMO_PROPERTY(PressureOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t PressureOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t PressureOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PressureOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PressureOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PressureOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(PressureOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(PressureOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(PressureOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(PressureOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(PressureOnOff, topLeftButtonEnabled), ATMO_PROPERTY(PressureOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(PressureOnOff, x);
    config.y = ATMO_PROPERTY(PressureOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(PressureOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(PressureOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(PressureOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(PressureOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(PressureOnOff, spanX);
	config.spanY = ATMO_PROPERTY(PressureOnOff, spanY);
    config.title = ATMO_PROPERTY(PressureOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(PressureOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(PressureOnOff, persist), ATMO_PROPERTY(PressureOnOff, differentStartup));
    ATMO_VARIABLE(PressureOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(PressureOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(PressureOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(PressureOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(PressureOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(PressureOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(PressureOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(PressureOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(PressureOnOff,pageHandle), 1, ATMO_ABILITY(PressureOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(PressureOnOff,pageHandle), 2, ATMO_ABILITY(PressureOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(PressureOnOff,pageHandle), 3, ATMO_ABILITY(PressureOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(PressureOnOff,pageHandle), ATMO_ABILITY(PressureOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(PressureOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t PressureOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(PressureOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t PressureOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(PressureOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t PressureOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t PressureOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t PressureOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t PressureOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t LightOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t LightOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(LightOnOff, x), ATMO_PROPERTY(LightOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t LightOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t LightOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t LightOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t LightOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t LightOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(LightOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(LightOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(LightOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(LightOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(LightOnOff, topLeftButtonEnabled), ATMO_PROPERTY(LightOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(LightOnOff, x);
    config.y = ATMO_PROPERTY(LightOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(LightOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(LightOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(LightOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(LightOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(LightOnOff, spanX);
	config.spanY = ATMO_PROPERTY(LightOnOff, spanY);
    config.title = ATMO_PROPERTY(LightOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(LightOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(LightOnOff, persist), ATMO_PROPERTY(LightOnOff, differentStartup));
    ATMO_VARIABLE(LightOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(LightOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(LightOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(LightOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(LightOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(LightOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(LightOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(LightOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(LightOnOff,pageHandle), 1, ATMO_ABILITY(LightOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(LightOnOff,pageHandle), 2, ATMO_ABILITY(LightOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(LightOnOff,pageHandle), 3, ATMO_ABILITY(LightOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(LightOnOff,pageHandle), ATMO_ABILITY(LightOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(LightOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t LightOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(LightOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t LightOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(LightOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t LightOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t LightOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t LightOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t LightOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TempOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TempOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(TempOnOff, x), ATMO_PROPERTY(TempOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t TempOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t TempOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t TempOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t TempOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t TempOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(TempOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(TempOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(TempOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(TempOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(TempOnOff, topLeftButtonEnabled), ATMO_PROPERTY(TempOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(TempOnOff, x);
    config.y = ATMO_PROPERTY(TempOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(TempOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(TempOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(TempOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(TempOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(TempOnOff, spanX);
	config.spanY = ATMO_PROPERTY(TempOnOff, spanY);
    config.title = ATMO_PROPERTY(TempOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(TempOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(TempOnOff, persist), ATMO_PROPERTY(TempOnOff, differentStartup));
    ATMO_VARIABLE(TempOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(TempOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(TempOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(TempOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(TempOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(TempOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(TempOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(TempOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(TempOnOff,pageHandle), 1, ATMO_ABILITY(TempOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(TempOnOff,pageHandle), 2, ATMO_ABILITY(TempOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(TempOnOff,pageHandle), 3, ATMO_ABILITY(TempOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(TempOnOff,pageHandle), ATMO_ABILITY(TempOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(TempOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t TempOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(TempOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t TempOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(TempOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t TempOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t TempOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t TempOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TempOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AirQualityOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AirQualityOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(AirQualityOnOff, x), ATMO_PROPERTY(AirQualityOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t AirQualityOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t AirQualityOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AirQualityOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AirQualityOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AirQualityOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(AirQualityOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(AirQualityOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(AirQualityOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(AirQualityOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(AirQualityOnOff, topLeftButtonEnabled), ATMO_PROPERTY(AirQualityOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(AirQualityOnOff, x);
    config.y = ATMO_PROPERTY(AirQualityOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(AirQualityOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(AirQualityOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(AirQualityOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(AirQualityOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(AirQualityOnOff, spanX);
	config.spanY = ATMO_PROPERTY(AirQualityOnOff, spanY);
    config.title = ATMO_PROPERTY(AirQualityOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(AirQualityOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(AirQualityOnOff, persist), ATMO_PROPERTY(AirQualityOnOff, differentStartup));
    ATMO_VARIABLE(AirQualityOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(AirQualityOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(AirQualityOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(AirQualityOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(AirQualityOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(AirQualityOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(AirQualityOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(AirQualityOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(AirQualityOnOff,pageHandle), 1, ATMO_ABILITY(AirQualityOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(AirQualityOnOff,pageHandle), 2, ATMO_ABILITY(AirQualityOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(AirQualityOnOff,pageHandle), 3, ATMO_ABILITY(AirQualityOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(AirQualityOnOff,pageHandle), ATMO_ABILITY(AirQualityOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(AirQualityOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t AirQualityOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(AirQualityOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t AirQualityOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(AirQualityOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t AirQualityOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t AirQualityOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t AirQualityOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AirQualityOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t VersionText_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t VersionText_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(VersionText, x), ATMO_PROPERTY(VersionText, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t VersionText_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t VersionText_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t VersionText_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t VersionText_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t VersionText_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t VersionText_setText(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_Value_t strVal;
    ATMO_InitValue(&strVal);
    ATMO_CreateValueConverted(&strVal, ATMO_DATATYPE_STRING, in);
    ATMO_UI_STATICTEXT_SetText(ATMO_VARIABLE(VersionText,pageHandle), strVal.data);
    ATMO_FreeValue(&strVal);
	return ATMO_Status_Success;
	
}


ATMO_Status_t VersionText_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(VersionText, pageHidden);
	config.textColor = ATMO_PROPERTY(VersionText, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(VersionText, topRightButtonEnabled),
		ATMO_PROPERTY(VersionText,bottomRightButtonEnabled), ATMO_PROPERTY(VersionText, topLeftButtonEnabled), ATMO_PROPERTY(VersionText, bottomLeftButtonEnabled));
    config.x = ATMO_PROPERTY(VersionText, x);
	config.y = ATMO_PROPERTY(VersionText, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(VersionText, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(VersionText, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(VersionText, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(VersionText, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(VersionText, spanX);
	config.spanY = ATMO_PROPERTY(VersionText, spanY);
    config.title = ATMO_PROPERTY(VersionText, pageTitle);
    config.titleHidden = ATMO_PROPERTY(VersionText, titleHidden);
	ATMO_UI_STATICTEXT_Init(&config);
	ATMO_VARIABLE(VersionText, pageHandle) = config.templateInstance;
    ATMO_UI_STATICTEXT_SetText(config.templateInstance, ATMO_PROPERTY(VersionText, text));
	ATMO_UI_STATICTEXT_SetTextSize(config.templateInstance, ATMO_PROPERTY(VersionText, fontSize));
	ATMO_UI_STATICTEXT_SetAlignment(config.templateInstance, ATMO_PROPERTY(VersionText, horizontalAlignment));
	ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(VersionText,pageHandle), 1, ATMO_ABILITY(VersionText, topRightButtonPressed));
	ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(VersionText,pageHandle), 2, ATMO_ABILITY(VersionText, bottomRightButtonPressed));
	ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(VersionText,pageHandle), 3, ATMO_ABILITY(VersionText, topLeftButtonPressed));
    ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(VersionText,pageHandle), 4, ATMO_ABILITY(VersionText, bottomLeftButtonPressed));
    
	if(!config.hidden)
	{
		ATMO_UI_STATICTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(VersionText,pageHandle), ATMO_ABILITY(VersionText, onDisplayed));
	}
    return ATMO_Status_Success;
    
}


ATMO_Status_t UserTempStorage_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	static unsigned int temp = 30;
	if(in)
	{
	    bool inc = false;
	    ATMO_GetBool(in, &inc);
	    if(inc)
	    {
	        temp++;
	    }
	    else if(temp > 0)
	    {
	        temp--;
	    }
	}
	
	if(out)
	{
	    ATMO_CreateValueUnsignedInt(out, temp);
	}
	return ATMO_Status_Success;
}


ATMO_Status_t IncTemp_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_Value_t myVal;
	ATMO_InitValue(&myVal);
	ATMO_CreateValueBool(&myVal, true);
	UserTempStorage_trigger(&myVal, NULL);
	ATMO_FreeValue(&myVal);
	return ATMO_Status_Success;
}


ATMO_Status_t DecTemp_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_Value_t myVal;
	ATMO_InitValue(&myVal);
	ATMO_CreateValueBool(&myVal, false);
	UserTempStorage_trigger(&myVal, NULL);
	ATMO_FreeValue(&myVal);
	return ATMO_Status_Success;
}


ATMO_Status_t CalcThermostatHeating_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	unsigned int realTemp, userTemp;
	ATMO_Value_t atmoRealTemp, atmoUserTemp;
	RealTempStorage_trigger(NULL, &atmoRealTemp);
	UserTempStorage_trigger(NULL, &atmoUserTemp);
	ATMO_GetUnsignedInt(&atmoUserTemp, &userTemp);
	ATMO_GetUnsignedInt(&atmoRealTemp, &realTemp);
	
	struct {
        char str[32];
        GUI_COLOR color;
    } icon_data;
    strcpy(icon_data.str, (userTemp > realTemp) ? "HEATING" : "COOLING");
    icon_data.color = (userTemp > realTemp) ? GUI_RED : GUI_BLUE;
	
	ATMO_CreateValueBinary(out, &icon_data, sizeof(icon_data));
	
	ATMO_FreeValue(&atmoRealTemp);
	ATMO_FreeValue(&atmoUserTemp);
	return ATMO_Status_Success;
}


ATMO_Status_t getHPa_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	unsigned int temp = 0;
	ATMO_GetUnsignedInt(in, &temp);
	ATMO_CreateValueUnsignedInt(out, temp/100);
	return ATMO_Status_Success;
}


ATMO_Status_t RealTempStorage_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	static unsigned int temp = 0;
	if(in)
	{
	    ATMO_GetUnsignedInt(in, &temp);
	}
	if(out)
	{
	    ATMO_CreateValueUnsignedInt(out, temp);
	}
	return ATMO_Status_Success;
}


ATMO_Status_t GetTapCount_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	static int x = 0;
	ATMO_CreateValueUnsignedInt(out, x++);
	return ATMO_Status_Success;
}


ATMO_Status_t FastInterval_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t FastInterval_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_INTERVAL_Handle_t intervalHandle;
    ATMO_INTERVAL_AddAbilityInterval(
		ATMO_PROPERTY(FastInterval, instance), 
		ATMO_ABILITY(FastInterval, interval), 
		ATMO_PROPERTY(FastInterval, time), 
		&intervalHandle
	);
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t FastInterval_interval(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TempChar_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TempChar_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(TempChar, instance),
		&ATMO_VARIABLE(TempChar, bleServiceHandle), 
		ATMO_PROPERTY(TempChar, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(TempChar, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(TempChar, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(TempChar, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(TempChar, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(TempChar, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(TempChar, writeDataType), ATMO_PROPERTY(TempChar, readDataType), ATMO_PROPERTY(TempChar, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(TempChar, instance),
		&ATMO_VARIABLE(TempChar, bleCharacteristicHandle), 
		ATMO_VARIABLE(TempChar, bleServiceHandle), 
		ATMO_PROPERTY(TempChar, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(TempChar, instance),
		ATMO_VARIABLE(TempChar, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(TempChar, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t TempChar_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(TempChar, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(TempChar, instance),
		ATMO_VARIABLE(TempChar, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t TempChar_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(TempChar, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t TempChar_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TempChar_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t HumidChar_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t HumidChar_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(HumidChar, instance),
		&ATMO_VARIABLE(HumidChar, bleServiceHandle), 
		ATMO_PROPERTY(HumidChar, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(HumidChar, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(HumidChar, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(HumidChar, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(HumidChar, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(HumidChar, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(HumidChar, writeDataType), ATMO_PROPERTY(HumidChar, readDataType), ATMO_PROPERTY(HumidChar, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(HumidChar, instance),
		&ATMO_VARIABLE(HumidChar, bleCharacteristicHandle), 
		ATMO_VARIABLE(HumidChar, bleServiceHandle), 
		ATMO_PROPERTY(HumidChar, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(HumidChar, instance),
		ATMO_VARIABLE(HumidChar, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(HumidChar, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t HumidChar_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(HumidChar, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(HumidChar, instance),
		ATMO_VARIABLE(HumidChar, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t HumidChar_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(HumidChar, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t HumidChar_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t HumidChar_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t LightChar_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t LightChar_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(LightChar, instance),
		&ATMO_VARIABLE(LightChar, bleServiceHandle), 
		ATMO_PROPERTY(LightChar, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(LightChar, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(LightChar, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(LightChar, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(LightChar, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(LightChar, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(LightChar, writeDataType), ATMO_PROPERTY(LightChar, readDataType), ATMO_PROPERTY(LightChar, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(LightChar, instance),
		&ATMO_VARIABLE(LightChar, bleCharacteristicHandle), 
		ATMO_VARIABLE(LightChar, bleServiceHandle), 
		ATMO_PROPERTY(LightChar, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(LightChar, instance),
		ATMO_VARIABLE(LightChar, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(LightChar, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t LightChar_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(LightChar, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(LightChar, instance),
		ATMO_VARIABLE(LightChar, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t LightChar_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(LightChar, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t LightChar_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t LightChar_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t PressureChar_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t PressureChar_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(PressureChar, instance),
		&ATMO_VARIABLE(PressureChar, bleServiceHandle), 
		ATMO_PROPERTY(PressureChar, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(PressureChar, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(PressureChar, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(PressureChar, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(PressureChar, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(PressureChar, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(PressureChar, writeDataType), ATMO_PROPERTY(PressureChar, readDataType), ATMO_PROPERTY(PressureChar, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(PressureChar, instance),
		&ATMO_VARIABLE(PressureChar, bleCharacteristicHandle), 
		ATMO_VARIABLE(PressureChar, bleServiceHandle), 
		ATMO_PROPERTY(PressureChar, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(PressureChar, instance),
		ATMO_VARIABLE(PressureChar, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(PressureChar, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t PressureChar_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(PressureChar, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(PressureChar, instance),
		ATMO_VARIABLE(PressureChar, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t PressureChar_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(PressureChar, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t PressureChar_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t PressureChar_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AirQualityChar_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AirQualityChar_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(AirQualityChar, instance),
		&ATMO_VARIABLE(AirQualityChar, bleServiceHandle), 
		ATMO_PROPERTY(AirQualityChar, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(AirQualityChar, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(AirQualityChar, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(AirQualityChar, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(AirQualityChar, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(AirQualityChar, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(AirQualityChar, writeDataType), ATMO_PROPERTY(AirQualityChar, readDataType), ATMO_PROPERTY(AirQualityChar, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(AirQualityChar, instance),
		&ATMO_VARIABLE(AirQualityChar, bleCharacteristicHandle), 
		ATMO_VARIABLE(AirQualityChar, bleServiceHandle), 
		ATMO_PROPERTY(AirQualityChar, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(AirQualityChar, instance),
		ATMO_VARIABLE(AirQualityChar, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(AirQualityChar, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t AirQualityChar_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(AirQualityChar, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(AirQualityChar, instance),
		ATMO_VARIABLE(AirQualityChar, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t AirQualityChar_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(AirQualityChar, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t AirQualityChar_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AirQualityChar_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TapCountChar_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TapCountChar_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(TapCountChar, instance),
		&ATMO_VARIABLE(TapCountChar, bleServiceHandle), 
		ATMO_PROPERTY(TapCountChar, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(TapCountChar, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(TapCountChar, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(TapCountChar, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(TapCountChar, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(TapCountChar, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(TapCountChar, writeDataType), ATMO_PROPERTY(TapCountChar, readDataType), ATMO_PROPERTY(TapCountChar, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(TapCountChar, instance),
		&ATMO_VARIABLE(TapCountChar, bleCharacteristicHandle), 
		ATMO_VARIABLE(TapCountChar, bleServiceHandle), 
		ATMO_PROPERTY(TapCountChar, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(TapCountChar, instance),
		ATMO_VARIABLE(TapCountChar, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(TapCountChar, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t TapCountChar_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(TapCountChar, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(TapCountChar, instance),
		ATMO_VARIABLE(TapCountChar, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t TapCountChar_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(TapCountChar, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t TapCountChar_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TapCountChar_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t ResetFunc_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ResetMCU();
	return ATMO_Status_Success;
}


ATMO_Status_t MPL3115Pressure_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MPL3115Pressure_setup(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_MPL3115_Config_t config;
	config.address = ATMO_PROPERTY(MPL3115Pressure, i2cAddress);
	config.i2cDriverInstance = ATMO_PROPERTY(MPL3115Pressure, i2cInstance);
	config.MPLsettings.mode = MPL_MODE_PRESSURE;
	config.MPLsettings.oversample = MPL_OS_0;			// oversampling = 1
	config.MPLsettings.autoAcquisitionTime = MPL_ST_0;	// Auto acquisition time = 1s
	config.MPLsettings.pressureOffset = ATMO_PROPERTY(MPL3115Pressure, pressureOffset);	// Offset pressure correction = 4*-128 = -512Pa (8 bits signed integer)
	config.MPLsettings.altitudeOffset = ATMO_PROPERTY(MPL3115Pressure, altitudeOffset);	// Offset altitude correction = 128m (signed 8 bits integer)
	config.MPLsettings.tempOffset = ATMO_PROPERTY(MPL3115Pressure, tempOffset);			// Offset temperature correction -8°C (0.0625°C/LSB)
	config.MPLsettings.fifoMode = FIFO_DISABLED;		// FIFO mode disabled
	config.MPLsettings.fifoWatermark = 5;				// 6 bits to set the number of FIFO samples required to trigger a watermark interrupt.
	config.MPLsettings.fifoINTpin = FIFO_INT1;			// set pin INT1 as output for FIFO interrupt

	return ( ATMO_MPL3115_Init(&config) == ATMO_MPL3115_Status_Success ) ? ATMO_Status_Success : ATMO_Status_Fail;

}


ATMO_Status_t MPL3115Pressure_setEnabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_MPL3115_SetEnabled(true);
return ATMO_Status_Success;
}


ATMO_Status_t MPL3115Pressure_setDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_MPL3115_SetEnabled(false);
return ATMO_Status_Success;
}


ATMO_Status_t MPL3115Pressure_setEnabledDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
bool enabled = false;
ATMO_GetBool(in, &enabled);
ATMO_MPL3115_SetEnabled(enabled);
return ATMO_Status_Success;
}


ATMO_Status_t MPL3115Pressure_readAltitude(ATMO_Value_t *in, ATMO_Value_t *out) {
    uint32_t altitudeMeters;
    if(ATMO_MPL3115_GetAltitude(&altitudeMeters) != ATMO_MPL3115_Status_Success)
    {
        ATMO_CreateValueVoid(out);
        return ATMO_Status_Fail;
    }
    ATMO_CreateValueInt(out, (int)altitudeMeters);
    return ATMO_Status_Success;
}


ATMO_Status_t MPL3115Pressure_readPressure(ATMO_Value_t *in, ATMO_Value_t *out) {
    uint32_t pressurePa;
    if(ATMO_MPL3115_GetPressure(&pressurePa) != ATMO_MPL3115_Status_Success)
    {
        ATMO_CreateValueVoid(out);
        return ATMO_Status_Fail;
    }
    ATMO_CreateValueInt(out, (int)pressurePa);
    return ATMO_Status_Success;
}


ATMO_Status_t MPL3115Pressure_readPressureKpa(ATMO_Value_t *in, ATMO_Value_t *out) {
    uint32_t pressurePa;
    if(ATMO_MPL3115_GetPressure(&pressurePa) != ATMO_MPL3115_Status_Success)
    {
        ATMO_CreateValueVoid(out);
        return ATMO_Status_Fail;
    }
    ATMO_CreateValueInt(out, (int)(pressurePa/1000));
    return ATMO_Status_Success;
}


ATMO_Status_t TSL2572AmbientLight_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TSL2572AmbientLight_setup(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_TSL2572_Config_t config;
	config.address = ATMO_PROPERTY(TSL2572AmbientLight, i2cAddress);
	config.i2cDriverInstance = ATMO_PROPERTY(TSL2572AmbientLight, i2cInstance);

	return ( ATMO_TSL2572_Init(&config) == ATMO_TSL2572_Status_Success ) ? ATMO_Status_Success : ATMO_Status_Fail;

}


ATMO_Status_t TSL2572AmbientLight_setEnabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_TSL2572_SetEnabled(true);
return ATMO_Status_Success;
}


ATMO_Status_t TSL2572AmbientLight_setDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_TSL2572_SetEnabled(false);
return ATMO_Status_Success;
}


ATMO_Status_t TSL2572AmbientLight_setEnabledDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
bool enabled = false;
ATMO_GetBool(in, &enabled);
ATMO_TSL2572_SetEnabled(enabled);
return ATMO_Status_Success;
}


ATMO_Status_t TSL2572AmbientLight_readAmbientLight(ATMO_Value_t *in, ATMO_Value_t *out) {
    float lightLux;
    if(ATMO_TSL2572_GetAmbientLight(&lightLux) != ATMO_TSL2572_Status_Success)
    {
        ATMO_CreateValueVoid(out);
        return ATMO_Status_Fail;
    }
    ATMO_CreateValueInt(out, (int)lightLux);
    return ATMO_Status_Success;
}


ATMO_Status_t CCS811AirQuality_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t CCS811AirQuality_setup(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_CCS811_Config_t config;
	config.operatingMode = ATMO_PROPERTY(CCS811AirQuality, operatingMode);
	config.address = ATMO_PROPERTY(CCS811AirQuality, i2cAddress);
	config.i2cDriverInstance = ATMO_PROPERTY(CCS811AirQuality, i2cInstance);

	return ( ATMO_CCS811_Init(&config) == ATMO_CCS811_Status_Success ) ? ATMO_Status_Success : ATMO_Status_Fail;

}


ATMO_Status_t CCS811AirQuality_setEnabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_CCS811_SetEnabled(true);
return ATMO_Status_Success;
}


ATMO_Status_t CCS811AirQuality_setDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_CCS811_SetEnabled(false);
return ATMO_Status_Success;
}


ATMO_Status_t CCS811AirQuality_setEnabledDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
bool enabled = false;
ATMO_GetBool(in, &enabled);
ATMO_CCS811_SetEnabled(enabled);
return ATMO_Status_Success;
}


ATMO_Status_t CCS811AirQuality_readTVOC(ATMO_Value_t *in, ATMO_Value_t *out) {
    uint16_t tvoc;

    if(ATMO_CCS811_GetTVOC(&tvoc) == ATMO_CCS811_Status_Success)
    {
        ATMO_CreateValueUnsignedInt(out, (unsigned int)tvoc);
    }
    else
    {
        ATMO_CreateValueVoid(out);
    }
    
    return ATMO_Status_Success;
}


ATMO_Status_t CCS811AirQuality_readCO2(ATMO_Value_t *in, ATMO_Value_t *out) {
    uint16_t co2;
    
    if(ATMO_CCS811_GetCO2(&co2) == ATMO_CCS811_Status_Success)
    {
        ATMO_CreateValueInt(out, (int)co2);
    }
    else
    {
        ATMO_CreateValueVoid(out);
    }
  
    return ATMO_Status_Success;
}


ATMO_Status_t Apps_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Apps_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Apps, x), ATMO_PROPERTY(Apps, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Apps_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Apps_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Apps_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Apps_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Apps_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Apps_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Apps, pageHidden);
	config.textColor = ATMO_PROPERTY(Apps, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Apps, topRightButtonEnabled),
    ATMO_PROPERTY(Apps,bottomRightButtonEnabled), ATMO_PROPERTY(Apps, topLeftButtonEnabled), ATMO_PROPERTY(Apps, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Apps, x);
    config.x = ATMO_PROPERTY(Apps, x);
    config.y = ATMO_PROPERTY(Apps, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Apps, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Apps, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Apps, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Apps, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Apps, spanX);
	config.spanY = ATMO_PROPERTY(Apps, spanY);
    config.title = ATMO_PROPERTY(Apps, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Apps, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Apps, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Apps, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Apps, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Apps,pageHandle), ATMO_ABILITY(Apps, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Apps,pageHandle), 1, ATMO_ABILITY(Apps, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Apps,pageHandle), 2, ATMO_ABILITY(Apps, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Apps,pageHandle), 3, ATMO_ABILITY(Apps, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Apps,pageHandle), 4, ATMO_ABILITY(Apps, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Apps, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Apps_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Apps_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Apps,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Settings_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Settings_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Settings, x), ATMO_PROPERTY(Settings, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Settings_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Settings_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Settings_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Settings_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Settings_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Settings_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Settings, pageHidden);
	config.textColor = ATMO_PROPERTY(Settings, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Settings, topRightButtonEnabled),
    ATMO_PROPERTY(Settings,bottomRightButtonEnabled), ATMO_PROPERTY(Settings, topLeftButtonEnabled), ATMO_PROPERTY(Settings, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Settings, x);
    config.x = ATMO_PROPERTY(Settings, x);
    config.y = ATMO_PROPERTY(Settings, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Settings, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Settings, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Settings, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Settings, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Settings, spanX);
	config.spanY = ATMO_PROPERTY(Settings, spanY);
    config.title = ATMO_PROPERTY(Settings, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Settings, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Settings, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Settings, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Settings, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Settings,pageHandle), ATMO_ABILITY(Settings, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Settings,pageHandle), 1, ATMO_ABILITY(Settings, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Settings,pageHandle), 2, ATMO_ABILITY(Settings, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Settings,pageHandle), 3, ATMO_ABILITY(Settings, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Settings,pageHandle), 4, ATMO_ABILITY(Settings, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Settings, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Settings_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Settings_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Settings,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Info_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Info_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Info, x), ATMO_PROPERTY(Info, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Info_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Info_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Info_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Info_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Info_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Info_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Info, pageHidden);
	config.textColor = ATMO_PROPERTY(Info, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Info, topRightButtonEnabled),
    ATMO_PROPERTY(Info,bottomRightButtonEnabled), ATMO_PROPERTY(Info, topLeftButtonEnabled), ATMO_PROPERTY(Info, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Info, x);
    config.x = ATMO_PROPERTY(Info, x);
    config.y = ATMO_PROPERTY(Info, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Info, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Info, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Info, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Info, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Info, spanX);
	config.spanY = ATMO_PROPERTY(Info, spanY);
    config.title = ATMO_PROPERTY(Info, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Info, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Info, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Info, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Info, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Info,pageHandle), ATMO_ABILITY(Info, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Info,pageHandle), 1, ATMO_ABILITY(Info, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Info,pageHandle), 2, ATMO_ABILITY(Info, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Info,pageHandle), 3, ATMO_ABILITY(Info, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Info,pageHandle), 4, ATMO_ABILITY(Info, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Info, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Info_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Info_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Info,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Sensor_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Sensor_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Sensor, x), ATMO_PROPERTY(Sensor, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Sensor_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Sensor_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Sensor_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Sensor_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Sensor_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Sensor_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Sensor, pageHidden);
	config.textColor = ATMO_PROPERTY(Sensor, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Sensor, topRightButtonEnabled),
    ATMO_PROPERTY(Sensor,bottomRightButtonEnabled), ATMO_PROPERTY(Sensor, topLeftButtonEnabled), ATMO_PROPERTY(Sensor, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Sensor, x);
    config.x = ATMO_PROPERTY(Sensor, x);
    config.y = ATMO_PROPERTY(Sensor, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Sensor, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Sensor, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Sensor, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Sensor, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Sensor, spanX);
	config.spanY = ATMO_PROPERTY(Sensor, spanY);
    config.title = ATMO_PROPERTY(Sensor, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Sensor, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Sensor, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Sensor, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Sensor, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Sensor,pageHandle), ATMO_ABILITY(Sensor, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Sensor,pageHandle), 1, ATMO_ABILITY(Sensor, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Sensor,pageHandle), 2, ATMO_ABILITY(Sensor, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Sensor,pageHandle), 3, ATMO_ABILITY(Sensor, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Sensor,pageHandle), 4, ATMO_ABILITY(Sensor, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Sensor, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Sensor_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Sensor_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Sensor,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t SlowInterval_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t SlowInterval_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_INTERVAL_Handle_t intervalHandle;
    ATMO_INTERVAL_AddAbilityInterval(
		ATMO_PROPERTY(SlowInterval, instance), 
		ATMO_ABILITY(SlowInterval, interval), 
		ATMO_PROPERTY(SlowInterval, time), 
		&intervalHandle
	);
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t SlowInterval_interval(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedSystemStatusDisplay_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedSystemStatusDisplay_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(EmbeddedSystemStatusDisplay, x), ATMO_PROPERTY(EmbeddedSystemStatusDisplay, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedSystemStatusDisplay_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedSystemStatusDisplay_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(EmbeddedSystemStatusDisplay, pageHidden);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(EmbeddedSystemStatusDisplay, topRightButtonEnabled),
    ATMO_PROPERTY(EmbeddedSystemStatusDisplay,bottomRightButtonEnabled), ATMO_PROPERTY(EmbeddedSystemStatusDisplay, topLeftButtonEnabled), ATMO_PROPERTY(EmbeddedSystemStatusDisplay, bottomLeftButtonEnabled));
    config.x = ATMO_PROPERTY(EmbeddedSystemStatusDisplay, x);
    config.y = ATMO_PROPERTY(EmbeddedSystemStatusDisplay, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(EmbeddedSystemStatusDisplay, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(EmbeddedSystemStatusDisplay, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(EmbeddedSystemStatusDisplay, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(EmbeddedSystemStatusDisplay, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(EmbeddedSystemStatusDisplay, spanX);
	config.spanY = ATMO_PROPERTY(EmbeddedSystemStatusDisplay, spanY);
    config.title = ATMO_PROPERTY(EmbeddedSystemStatusDisplay, pageTitle);
    config.titleHidden = ATMO_PROPERTY(EmbeddedSystemStatusDisplay, titleHidden);
    ATMO_UI_SYSTEMSTATUS_Init(&config);
    
}


ATMO_Status_t EmbeddedNxpRpkUserButtons_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedNxpRpkUserButtons_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_MK64F_GPIO_EnableResetCombo(ATMO_PROPERTY(EmbeddedNxpRpkUserButtons, enableResetCombo));
    ATMO_MK64F_GPIO_EnableDisplayToggleCombo(ATMO_PROPERTY(EmbeddedNxpRpkUserButtons, enableDisplayToggleCombo));
    ATMO_MK64F_UserButton_RegisterAbilityHandle(ATMO_MK64F_SW1_Pushed, ATMO_ABILITY(EmbeddedNxpRpkUserButtons, topRightPushed));
    ATMO_MK64F_UserButton_RegisterAbilityHandle(ATMO_MK64F_SW2_Pushed, ATMO_ABILITY(EmbeddedNxpRpkUserButtons, bottomRightPushed));
    ATMO_MK64F_UserButton_RegisterAbilityHandle(ATMO_MK64F_SW3_Pushed, ATMO_ABILITY(EmbeddedNxpRpkUserButtons, topLeftPushed));
    ATMO_MK64F_UserButton_RegisterAbilityHandle(ATMO_MK64F_SW4_Pushed, ATMO_ABILITY(EmbeddedNxpRpkUserButtons, bottomLeftPushed));
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkUserButtons_topRightPushed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkUserButtons_bottomRightPushed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkUserButtons_topLeftPushed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkUserButtons_bottomLeftPushed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t SX9500Touch_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t SX9500Touch_setup(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_SX9500_Config_t config;
	config.address = ATMO_PROPERTY(SX9500Touch, i2cAddress);
	config.i2cDriverInstance = ATMO_PROPERTY(SX9500Touch, i2cInstance);
	config.gpioDriverInstance = ATMO_PROPERTY(SX9500Touch, gpioInstance);
	config.interruptEnabled = ATMO_PROPERTY(SX9500Touch, interruptEnabled);
	config.interruptPin = ATMO_PROPERTY(SX9500Touch, interruptGpio);
	ATMO_SX9500_Init(&config);
	ATMO_SX9500_RegisterTouchedAbilityHandle(SX9500_Touched_Up, ATMO_ABILITY(SX9500Touch, pressUp));
	ATMO_SX9500_RegisterTouchedAbilityHandle(SX9500_Touched_Down, ATMO_ABILITY(SX9500Touch, pressDown));
	ATMO_SX9500_RegisterTouchedAbilityHandle(SX9500_Touched_Left, ATMO_ABILITY(SX9500Touch, pressLeft));
	ATMO_SX9500_RegisterTouchedAbilityHandle(SX9500_Touched_Right, ATMO_ABILITY(SX9500Touch, pressRight));
	return ATMO_Status_Success;
}


ATMO_Status_t SX9500Touch_getTouchData(ATMO_Value_t *in, ATMO_Value_t *out) {
	return;
}


ATMO_Status_t SX9500Touch_pressUp(ATMO_Value_t *in, ATMO_Value_t *out) {
SX9500_TouchState_t touchState;
ATMO_GetBinary(in, &touchState, sizeof(touchState));
ATMO_CreateValueBinary(out, &touchState, sizeof(touchState));
return ATMO_Status_Success;
}


ATMO_Status_t SX9500Touch_pressDown(ATMO_Value_t *in, ATMO_Value_t *out) {
SX9500_TouchState_t touchState;
ATMO_GetBinary(in, &touchState, sizeof(touchState));
ATMO_CreateValueBinary(out, &touchState, sizeof(touchState));
return ATMO_Status_Success;
}


ATMO_Status_t SX9500Touch_pressLeft(ATMO_Value_t *in, ATMO_Value_t *out) {
SX9500_TouchState_t touchState;
ATMO_GetBinary(in, &touchState, sizeof(touchState));
ATMO_CreateValueBinary(out, &touchState, sizeof(touchState));
return ATMO_Status_Success;
}


ATMO_Status_t SX9500Touch_pressRight(ATMO_Value_t *in, ATMO_Value_t *out) {
SX9500_TouchState_t touchState;
ATMO_GetBinary(in, &touchState, sizeof(touchState));
ATMO_CreateValueBinary(out, &touchState, sizeof(touchState));
return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedPageController_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedPageController_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_PAGE_CONTROLLER_Config_t config;
	config.enableUpDownNavLabels = ATMO_PROPERTY(EmbeddedPageController, upDownNavigationLabelsEnabled);
	config.enableLeftRightNavLabels = ATMO_PROPERTY(EmbeddedPageController, leftRightNavigationLabelsEnabled);
	ATMO_UI_Page_SetConfiguration(&config);
    return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedPageController_displayRootPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	ATMO_UI_Page_DisplayRootPage();
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedPageController_navigateUp(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_ProcessNavButton(ATMO_UI_PAGE_NAV_UP);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedPageController_navigateDown(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_ProcessNavButton(ATMO_UI_PAGE_NAV_DOWN);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedPageController_navigateLeft(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_ProcessNavButton(ATMO_UI_PAGE_NAV_LEFT);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedPageController_navigateRight(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_ProcessNavButton(ATMO_UI_PAGE_NAV_RIGHT);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedPageController_processTopRightButton(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_ProcessUserButton(1);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedPageController_processBottomRightButton(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_ProcessUserButton(2);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedPageController_processTopLeftButton(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_ProcessUserButton(3);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedPageController_processBottomLeftButton(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_ProcessUserButton(4);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkThread_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedNxpRpkThread_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkThread_join(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_THREAD_VOLANSYS_TryJoin();
    return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkThread_setTemperature(ATMO_Value_t *in, ATMO_Value_t *out) {

    int temperature;
    ATMO_GetInt(in, &temperature);
    ATMO_THREAD_VOLANSYS_SetTemperature(temperature);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkThread_setHumidity(ATMO_Value_t *in, ATMO_Value_t *out) {

    int humidity;
    ATMO_GetInt(in, &humidity);
    ATMO_THREAD_VOLANSYS_SetHumidity(humidity);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkThread_setAmbientLight(ATMO_Value_t *in, ATMO_Value_t *out) {

    int ambientLight;
    ATMO_GetInt(in, &ambientLight);
    ATMO_THREAD_VOLANSYS_SetAmbientLight(ambientLight);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkThread_setPressureHpa(ATMO_Value_t *in, ATMO_Value_t *out) {

    int press;
    ATMO_GetInt(in, &press);
    ATMO_THREAD_VOLANSYS_SetPressure(press);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkThread_setAirQualityTvoc(ATMO_Value_t *in, ATMO_Value_t *out) {

    int air;
    ATMO_GetInt(in, &air);
    ATMO_THREAD_VOLANSYS_SetAirQualityTvoc(air);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkThread_setAirQualityCO2(ATMO_Value_t *in, ATMO_Value_t *out) {

    int air;
    ATMO_GetInt(in, &air);
    ATMO_THREAD_VOLANSYS_SetAirQualityCO2(air);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkThread_setAccelX(ATMO_Value_t *in, ATMO_Value_t *out) {

    float value = 0.0;
    ATMO_GetFloat(in, &value);
    ATMO_THREAD_VOLANSYS_SetAccelX(value);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkThread_setAccelY(ATMO_Value_t *in, ATMO_Value_t *out) {

    float value = 0.0;
    ATMO_GetFloat(in, &value);
    ATMO_THREAD_VOLANSYS_SetAccelY(value);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkThread_setAccelZ(ATMO_Value_t *in, ATMO_Value_t *out) {

    float value = 0.0;
    ATMO_GetFloat(in, &value);
    ATMO_THREAD_VOLANSYS_SetAccelZ(value);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkThread_setMagX(ATMO_Value_t *in, ATMO_Value_t *out) {

    float value = 0.0;
    ATMO_GetFloat(in, &value);
    ATMO_THREAD_VOLANSYS_SetMagX(value);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkThread_setMagY(ATMO_Value_t *in, ATMO_Value_t *out) {

    float value = 0.0;
    ATMO_GetFloat(in, &value);
    ATMO_THREAD_VOLANSYS_SetMagY(value);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkThread_setMagZ(ATMO_Value_t *in, ATMO_Value_t *out) {

    float value = 0.0;
    ATMO_GetFloat(in, &value);
    ATMO_THREAD_VOLANSYS_SetMagZ(value);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkThread_setGyroX(ATMO_Value_t *in, ATMO_Value_t *out) {

    float value = 0.0;
    ATMO_GetFloat(in, &value);
    ATMO_THREAD_VOLANSYS_SetRotspeedX(value);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkThread_setGyroY(ATMO_Value_t *in, ATMO_Value_t *out) {

    float value = 0.0;
    ATMO_GetFloat(in, &value);
    ATMO_THREAD_VOLANSYS_SetRotspeedY(value);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkThread_setGyroZ(ATMO_Value_t *in, ATMO_Value_t *out) {

    float value = 0.0;
    ATMO_GetFloat(in, &value);
    ATMO_THREAD_VOLANSYS_SetRotspeedZ(value);
	return ATMO_Status_Success;
	
}


ATMO_Status_t GetNextColor_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	uint8_t color, brightness;
	RGB_Led_Get_State(&brightness, &color);
	color = (color + 1) % (RGB_LED_COLOR_BLACK + 1);
	ATMO_CreateValueUnsignedInt(out, color);
	return ATMO_Status_Success;
}


ATMO_Status_t GetColorText_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	unsigned int color = 0;
	ATMO_GetUnsignedInt(in, &color);
	switch(color)
	{
	    case RGB_LED_COLOR_RED:
	    {
	        ATMO_CreateValueString(out, "Color: Red");
	        break;
	    }
	    case RGB_LED_COLOR_GREEN:
	    {
	        ATMO_CreateValueString(out, "Color: Green");
	        break;
	    }
	    case RGB_LED_COLOR_BLUE:
	    {
	        ATMO_CreateValueString(out, "Color: Blue");
	        break;
	    }
	    case RGB_LED_COLOR_WHITE:
	    {
	        ATMO_CreateValueString(out, "Color: White");
	        break;
	    }
	    case RGB_LED_COLOR_CYAN:
	    {
	        ATMO_CreateValueString(out, "Color: Cyan");
	        break;
	    }
	    case RGB_LED_COLOR_YELLOW:
	    {
	        ATMO_CreateValueString(out, "Color: Yellow");
	        break;
	    }
	     case RGB_LED_COLOR_PURPLE:
	    {
	        ATMO_CreateValueString(out, "Color: Purple");
	        break;
	    }
	    case RGB_LED_COLOR_BLACK:
	    {
	        ATMO_CreateValueString(out, "Color: Off");
	        break;
	    }
	    default:
	    {
	        ATMO_CreateValueString(out, "Color: Unknown/Custom");
	        break;  
	    }
	}
	return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    RGB_Led_Set_State(RGB_LED_BRIGHT_HIGH, RGB_LED_COLOR_BLACK);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setColorPreset(ATMO_Value_t *in, ATMO_Value_t *out) {

    unsigned int desiredColor = 0;
    ATMO_GetUnsignedInt(in, &desiredColor);

    uint8_t brightness = 0;
    uint8_t color = 0;
    RGB_Led_Get_State(&brightness, &color);
    RGB_Led_Set_State(brightness, desiredColor);
    return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setBrightnessLow(ATMO_Value_t *in, ATMO_Value_t *out) {

    uint8_t brightness = 0;
    uint8_t color = 0;
    RGB_Led_Get_State(&brightness, &color);
    RGB_Led_Set_State(RGB_LED_BRIGHT_LOW, color);
    return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setBrightnessOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    uint8_t brightness = 0;
    uint8_t color = 0;
    RGB_Led_Get_State(&brightness, &color);
    RGB_Led_Set_State(RGB_LED_BRIGHT_OFF, color);
    return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setBrightnessMedium(ATMO_Value_t *in, ATMO_Value_t *out) {

    uint8_t brightness = 0;
    uint8_t color = 0;
    RGB_Led_Get_State(&brightness, &color);
    RGB_Led_Set_State(RGB_LED_BRIGHT_MEDIUM, color);
    return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setBrightnessHigh(ATMO_Value_t *in, ATMO_Value_t *out) {

    uint8_t brightness = 0;
    uint8_t color = 0;
    RGB_Led_Get_State(&brightness, &color);
    RGB_Led_Set_State(RGB_LED_BRIGHT_HIGH, color);
    return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setRedOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    RGB_Led_Set_State(RGB_LED_BRIGHT_HIGH, RGB_LED_COLOR_RED);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setGreenOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    RGB_Led_Set_State(RGB_LED_BRIGHT_HIGH, RGB_LED_COLOR_GREEN);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setBlueOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    RGB_Led_Set_State(RGB_LED_BRIGHT_HIGH, RGB_LED_COLOR_BLUE);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setWhiteOn(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_toggleRed(ATMO_Value_t *in, ATMO_Value_t *out) {

	uint8_t color, brightness;
    RGB_Led_Get_State(&brightness, &color);
    if(brightness == RGB_LED_BRIGHT_OFF || color == RGB_LED_COLOR_BLACK)
    {
        brightness = RGB_LED_BRIGHT_HIGH;
    }
    else
    {
        brightness = RGB_LED_BRIGHT_OFF;
    }

    RGB_Led_Set_State(brightness, RGB_LED_COLOR_RED);
    return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_toggleGreen(ATMO_Value_t *in, ATMO_Value_t *out) {

	uint8_t color, brightness;
    RGB_Led_Get_State(&brightness, &color);
    if(brightness == RGB_LED_BRIGHT_OFF || color == RGB_LED_COLOR_BLACK)
    {
        brightness = RGB_LED_BRIGHT_HIGH;
    }
    else
    {
        brightness = RGB_LED_BRIGHT_OFF;
    }

    RGB_Led_Set_State(brightness, RGB_LED_COLOR_GREEN);
    return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_toggleBlue(ATMO_Value_t *in, ATMO_Value_t *out) {

	uint8_t color, brightness;
    RGB_Led_Get_State(&brightness, &color);
    if(brightness == RGB_LED_BRIGHT_OFF || color == RGB_LED_COLOR_BLACK)
    {
        brightness = RGB_LED_BRIGHT_HIGH;
    }
    else
    {
        brightness = RGB_LED_BRIGHT_OFF;
    }

    RGB_Led_Set_State(brightness, RGB_LED_COLOR_BLUE);
    return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    uint8_t brightness, color;
    RGB_Led_Get_State(&brightness, &color);
    RGB_Led_Set_State(brightness, RGB_LED_COLOR_BLACK);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkRgbLed_setColorHex(ATMO_Value_t *in, ATMO_Value_t *out) {

    unsigned int color = 0;
    ATMO_GetUnsignedInt(in, &color);
    uint8_t red = (color >> 16) & 0xFF;
    uint8_t green = (color >> 8) & 0xFF;
    uint8_t blue = color & 0xFF;
    Rgb_Led_Set_Colors(red, green, blue);  
    ATMO_CreateValueUnsignedInt(out, color);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkBuzzer_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedNxpRpkBuzzer_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkBuzzer_beep(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_MK64F_Buzzer_On();
    ATMO_PLATFORM_DelayMilliseconds(200);
    ATMO_MK64F_Buzzer_Off();
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkBuzzer_turnOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_MK64F_Buzzer_On();
    ATMO_CreateValueBool(out, true);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkBuzzer_turnOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_MK64F_Buzzer_Off();
    ATMO_CreateValueBool(out, false);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkBuzzer_toggle(ATMO_Value_t *in, ATMO_Value_t *out) {

    bool newState = false;
    ATMO_MK64F_Buzzer_Toggle(&newState);
    ATMO_CreateValueBool(out, newState);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkBuzzer_setState(ATMO_Value_t *in, ATMO_Value_t *out) {

    bool on = false;
    ATMO_GetBool(in, &on);

    if( on )
    {
        ATMO_MK64F_Buzzer_On();
    }
    else
    {
        ATMO_MK64F_Buzzer_Off();
    }
    ATMO_CreateValueBool(out, on);
    
	return ATMO_Status_Success;
    
}


ATMO_Status_t GetTempStr_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	int temp;
	ATMO_GetInt(in, &temp);
	char str[32];
	sprintf(str, "%d C", temp);
	ATMO_CreateValueString(out, str);
	return ATMO_Status_Success;
}


ATMO_Status_t GetLightStr_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	unsigned int temp;
	ATMO_GetUnsignedInt(in, &temp);
	char str[32];
	sprintf(str, "%u lx", temp);
	ATMO_CreateValueString(out, str);
	return ATMO_Status_Success;
}


ATMO_Status_t GetPressureStr_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	unsigned int temp;
	ATMO_GetUnsignedInt(in, &temp);
	char str[32];
	sprintf(str, "%u hPa", temp);
	ATMO_CreateValueString(out, str);
	return ATMO_Status_Success;
}


ATMO_Status_t GetAirQualityStr_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	unsigned int temp;
	ATMO_GetUnsignedInt(in, &temp);
	char str[32];
	sprintf(str, "%u ppb", temp);
	ATMO_CreateValueString(out, str);
	return ATMO_Status_Success;
}


ATMO_Status_t Thermostat_Pg_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Thermostat_Pg_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Thermostat_Pg, x), ATMO_PROPERTY(Thermostat_Pg, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Thermostat_Pg_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Thermostat_Pg_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Thermostat_Pg_setIconLabelAndColor(ATMO_Value_t *in, ATMO_Value_t *out) {

    struct {
        char str[32];
        GUI_COLOR color;
    } icon_data;
 
    ATMO_GetBinary(in, &icon_data, sizeof(icon_data));
    ATMO_UI_ICONLINES_SetIconLabelColor(ATMO_VARIABLE(Thermostat_Pg, pageHandle), icon_data.str, icon_data.color);
    return ATMO_Status_Success;
    
}


ATMO_Status_t Thermostat_Pg_setIconLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char str[32];
    ATMO_GetString(in, str, 32);
    ATMO_UI_ICONLINES_SetIconLabel(ATMO_VARIABLE(Thermostat_Pg, pageHandle), str);
    return ATMO_Status_Success;
    
}


ATMO_Status_t Thermostat_Pg_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(Thermostat_Pg, pageHidden);
    config.textColor = ATMO_PROPERTY(Thermostat_Pg, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Thermostat_Pg, topRightButtonEnabled),
    ATMO_PROPERTY(Thermostat_Pg,bottomRightButtonEnabled), ATMO_PROPERTY(Thermostat_Pg, topLeftButtonEnabled), ATMO_PROPERTY(Thermostat_Pg, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Thermostat_Pg, x);
    config.y = ATMO_PROPERTY(Thermostat_Pg, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Thermostat_Pg, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Thermostat_Pg, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Thermostat_Pg, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Thermostat_Pg, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Thermostat_Pg, spanX);
	config.spanY = ATMO_PROPERTY(Thermostat_Pg, spanY);
    config.title = ATMO_PROPERTY(Thermostat_Pg, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Thermostat_Pg, titleHidden);
	ATMO_UI_ICONLINES_Init(&config, ATMO_PROPERTY(Thermostat_Pg, numLines), false);
	ATMO_VARIABLE(Thermostat_Pg, pageHandle) = config.templateInstance;
    ATMO_UI_ICONLINES_SetMainText(config.templateInstance, 0, ATMO_PROPERTY(Thermostat_Pg, line1Text));
    ATMO_UI_ICONLINES_SetMainText(config.templateInstance, 1, ATMO_PROPERTY(Thermostat_Pg, line2Text));
    ATMO_UI_ICONLINES_SetMainText(config.templateInstance, 2, ATMO_PROPERTY(Thermostat_Pg, line3Text));
    ATMO_UI_ICONLINES_SetMainText(config.templateInstance, 3, ATMO_PROPERTY(Thermostat_Pg, line4Text));
    ATMO_UI_ICONLINES_SetIconLabel(config.templateInstance, ATMO_PROPERTY(Thermostat_Pg, iconLabel));
    ATMO_UI_ICONLINES_RegisterButtonAbilityHandle(ATMO_VARIABLE(Thermostat_Pg,pageHandle), 1, ATMO_ABILITY(Thermostat_Pg, topRightButtonPressed));
	ATMO_UI_ICONLINES_RegisterButtonAbilityHandle(ATMO_VARIABLE(Thermostat_Pg,pageHandle), 2, ATMO_ABILITY(Thermostat_Pg, bottomRightButtonPressed));
	ATMO_UI_ICONLINES_RegisterButtonAbilityHandle(ATMO_VARIABLE(Thermostat_Pg,pageHandle), 3, ATMO_ABILITY(Thermostat_Pg, topLeftButtonPressed));
    ATMO_UI_ICONLINES_RegisterButtonAbilityHandle(ATMO_VARIABLE(Thermostat_Pg,pageHandle), 4, ATMO_ABILITY(Thermostat_Pg, bottomLeftButtonPressed));
    ATMO_UI_ICONLINES_SetIcon(config.templateInstance, ATMO_PROPERTY(Thermostat_Pg, icon));
    ATMO_UI_ICONLINES_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Thermostat_Pg,pageHandle), ATMO_ABILITY(Thermostat_Pg, onDisplayed));
    ATMO_UI_ICONLINES_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Thermostat_Pg, onLeave));
    return ATMO_Status_Success;
    
}


ATMO_Status_t Thermostat_Pg_setLine1Text(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_ICONLINES_SetMainText(ATMO_VARIABLE(Thermostat_Pg,pageHandle), 0, label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Thermostat_Pg_setLine2Text(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_ICONLINES_SetMainText(ATMO_VARIABLE(Thermostat_Pg,pageHandle), 1, label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Thermostat_Pg_setLine3Text(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_ICONLINES_SetMainText(ATMO_VARIABLE(Thermostat_Pg,pageHandle), 2, label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Thermostat_Pg_setLine4Text(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_ICONLINES_SetMainText(ATMO_VARIABLE(Thermostat_Pg,pageHandle), 3, label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Thermostat_Pg_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Thermostat_Pg_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Thermostat_Pg_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Thermostat_Pg_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t GetUserTempStr_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_Value_t userTemp;
	UserTempStorage_trigger(NULL, &userTemp);
	int userTempVal;
	ATMO_GetInt(&userTemp, &userTempVal);
	char str[32];
	sprintf(str, "%d C", userTempVal);
	ATMO_CreateValueString(out, str);
	ATMO_FreeValue(&userTemp);
	return ATMO_Status_Success;
}


ATMO_Status_t BtOnFunc_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_MK64F_BLE_SetEnabled(NULL, true);
	return ATMO_Status_Success;
}


ATMO_Status_t BtOffFunc_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_MK64F_BLE_SetEnabled(NULL, false);
	return ATMO_Status_Success;
}


ATMO_Status_t ThreadOnFunc_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_THREAD_VOLANSYS_SetEnabled(true);
	return ATMO_Status_Success;
}


ATMO_Status_t ThreadOffFunc_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_THREAD_VOLANSYS_SetEnabled(false);
	return ATMO_Status_Success;
}


ATMO_Status_t NfcOnFunc_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	Connect_NTAG_A1006();
	return ATMO_Status_Success;
}


ATMO_Status_t NfcOffFunc_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	Disconnect_NTAG_A1006();
	return ATMO_Status_Success;
}


ATMO_Status_t Reset_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Reset_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Reset, x), ATMO_PROPERTY(Reset, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Reset_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Reset_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Reset_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Reset_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Reset_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Reset_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Reset, pageHidden);
	config.textColor = ATMO_PROPERTY(Reset, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Reset, topRightButtonEnabled),
    ATMO_PROPERTY(Reset,bottomRightButtonEnabled), ATMO_PROPERTY(Reset, topLeftButtonEnabled), ATMO_PROPERTY(Reset, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Reset, x);
    config.x = ATMO_PROPERTY(Reset, x);
    config.y = ATMO_PROPERTY(Reset, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Reset, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Reset, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Reset, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Reset, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Reset, spanX);
	config.spanY = ATMO_PROPERTY(Reset, spanY);
    config.title = ATMO_PROPERTY(Reset, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Reset, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Reset, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Reset, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Reset, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Reset,pageHandle), ATMO_ABILITY(Reset, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Reset,pageHandle), 1, ATMO_ABILITY(Reset, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Reset,pageHandle), 2, ATMO_ABILITY(Reset, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Reset,pageHandle), 3, ATMO_ABILITY(Reset, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Reset,pageHandle), 4, ATMO_ABILITY(Reset, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Reset, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Reset_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Reset_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Reset,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Motion_Page_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Motion_Page_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Motion_Page, x), ATMO_PROPERTY(Motion_Page, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Motion_Page_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Motion_Page_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Motion_Page_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Motion_Page_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Motion_Page_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Motion_Page_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Motion_Page, pageHidden);
	config.textColor = ATMO_PROPERTY(Motion_Page, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Motion_Page, topRightButtonEnabled),
    ATMO_PROPERTY(Motion_Page,bottomRightButtonEnabled), ATMO_PROPERTY(Motion_Page, topLeftButtonEnabled), ATMO_PROPERTY(Motion_Page, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Motion_Page, x);
    config.x = ATMO_PROPERTY(Motion_Page, x);
    config.y = ATMO_PROPERTY(Motion_Page, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Motion_Page, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Motion_Page, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Motion_Page, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Motion_Page, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Motion_Page, spanX);
	config.spanY = ATMO_PROPERTY(Motion_Page, spanY);
    config.title = ATMO_PROPERTY(Motion_Page, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Motion_Page, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Motion_Page, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Motion_Page, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Motion_Page, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Motion_Page,pageHandle), ATMO_ABILITY(Motion_Page, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Motion_Page,pageHandle), 1, ATMO_ABILITY(Motion_Page, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Motion_Page,pageHandle), 2, ATMO_ABILITY(Motion_Page, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Motion_Page,pageHandle), 3, ATMO_ABILITY(Motion_Page, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Motion_Page,pageHandle), 4, ATMO_ABILITY(Motion_Page, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Motion_Page, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Motion_Page_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Motion_Page_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Motion_Page,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Freefall_Pg_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Freefall_Pg_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Freefall_Pg, x), ATMO_PROPERTY(Freefall_Pg, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Freefall_Pg_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Freefall_Pg_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Freefall_Pg_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Freefall_Pg_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Freefall_Pg_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Freefall_Pg_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Freefall_Pg, pageHidden);
	config.textColor = ATMO_PROPERTY(Freefall_Pg, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Freefall_Pg, topRightButtonEnabled),
    ATMO_PROPERTY(Freefall_Pg,bottomRightButtonEnabled), ATMO_PROPERTY(Freefall_Pg, topLeftButtonEnabled), ATMO_PROPERTY(Freefall_Pg, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Freefall_Pg, x);
    config.x = ATMO_PROPERTY(Freefall_Pg, x);
    config.y = ATMO_PROPERTY(Freefall_Pg, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Freefall_Pg, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Freefall_Pg, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Freefall_Pg, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Freefall_Pg, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Freefall_Pg, spanX);
	config.spanY = ATMO_PROPERTY(Freefall_Pg, spanY);
    config.title = ATMO_PROPERTY(Freefall_Pg, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Freefall_Pg, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Freefall_Pg, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Freefall_Pg, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Freefall_Pg, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Freefall_Pg,pageHandle), ATMO_ABILITY(Freefall_Pg, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Freefall_Pg,pageHandle), 1, ATMO_ABILITY(Freefall_Pg, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Freefall_Pg,pageHandle), 2, ATMO_ABILITY(Freefall_Pg, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Freefall_Pg,pageHandle), 3, ATMO_ABILITY(Freefall_Pg, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Freefall_Pg,pageHandle), 4, ATMO_ABILITY(Freefall_Pg, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Freefall_Pg, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Freefall_Pg_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Freefall_Pg_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Freefall_Pg,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Humid_Pg_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Humid_Pg_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Humid_Pg, x), ATMO_PROPERTY(Humid_Pg, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Humid_Pg_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Humid_Pg_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Humid_Pg_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Humid_Pg_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Humid_Pg_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Humid_Pg_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Humid_Pg, pageHidden);
	config.textColor = ATMO_PROPERTY(Humid_Pg, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Humid_Pg, topRightButtonEnabled),
    ATMO_PROPERTY(Humid_Pg,bottomRightButtonEnabled), ATMO_PROPERTY(Humid_Pg, topLeftButtonEnabled), ATMO_PROPERTY(Humid_Pg, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Humid_Pg, x);
    config.x = ATMO_PROPERTY(Humid_Pg, x);
    config.y = ATMO_PROPERTY(Humid_Pg, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Humid_Pg, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Humid_Pg, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Humid_Pg, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Humid_Pg, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Humid_Pg, spanX);
	config.spanY = ATMO_PROPERTY(Humid_Pg, spanY);
    config.title = ATMO_PROPERTY(Humid_Pg, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Humid_Pg, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Humid_Pg, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Humid_Pg, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Humid_Pg, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Humid_Pg,pageHandle), ATMO_ABILITY(Humid_Pg, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Humid_Pg,pageHandle), 1, ATMO_ABILITY(Humid_Pg, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Humid_Pg,pageHandle), 2, ATMO_ABILITY(Humid_Pg, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Humid_Pg,pageHandle), 3, ATMO_ABILITY(Humid_Pg, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Humid_Pg,pageHandle), 4, ATMO_ABILITY(Humid_Pg, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Humid_Pg, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Humid_Pg_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Humid_Pg_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Humid_Pg,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Light_Pg_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Light_Pg_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Light_Pg, x), ATMO_PROPERTY(Light_Pg, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Light_Pg_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Light_Pg_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Light_Pg_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Light_Pg_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Light_Pg_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Light_Pg_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Light_Pg, pageHidden);
	config.textColor = ATMO_PROPERTY(Light_Pg, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Light_Pg, topRightButtonEnabled),
    ATMO_PROPERTY(Light_Pg,bottomRightButtonEnabled), ATMO_PROPERTY(Light_Pg, topLeftButtonEnabled), ATMO_PROPERTY(Light_Pg, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Light_Pg, x);
    config.x = ATMO_PROPERTY(Light_Pg, x);
    config.y = ATMO_PROPERTY(Light_Pg, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Light_Pg, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Light_Pg, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Light_Pg, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Light_Pg, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Light_Pg, spanX);
	config.spanY = ATMO_PROPERTY(Light_Pg, spanY);
    config.title = ATMO_PROPERTY(Light_Pg, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Light_Pg, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Light_Pg, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Light_Pg, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Light_Pg, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Light_Pg,pageHandle), ATMO_ABILITY(Light_Pg, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Light_Pg,pageHandle), 1, ATMO_ABILITY(Light_Pg, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Light_Pg,pageHandle), 2, ATMO_ABILITY(Light_Pg, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Light_Pg,pageHandle), 3, ATMO_ABILITY(Light_Pg, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Light_Pg,pageHandle), 4, ATMO_ABILITY(Light_Pg, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Light_Pg, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Light_Pg_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Light_Pg_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Light_Pg,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Pressure_Pg_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Pressure_Pg_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Pressure_Pg, x), ATMO_PROPERTY(Pressure_Pg, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Pressure_Pg_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Pressure_Pg_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Pressure_Pg_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Pressure_Pg_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Pressure_Pg_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Pressure_Pg_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Pressure_Pg, pageHidden);
	config.textColor = ATMO_PROPERTY(Pressure_Pg, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Pressure_Pg, topRightButtonEnabled),
    ATMO_PROPERTY(Pressure_Pg,bottomRightButtonEnabled), ATMO_PROPERTY(Pressure_Pg, topLeftButtonEnabled), ATMO_PROPERTY(Pressure_Pg, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Pressure_Pg, x);
    config.x = ATMO_PROPERTY(Pressure_Pg, x);
    config.y = ATMO_PROPERTY(Pressure_Pg, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Pressure_Pg, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Pressure_Pg, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Pressure_Pg, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Pressure_Pg, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Pressure_Pg, spanX);
	config.spanY = ATMO_PROPERTY(Pressure_Pg, spanY);
    config.title = ATMO_PROPERTY(Pressure_Pg, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Pressure_Pg, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Pressure_Pg, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Pressure_Pg, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Pressure_Pg, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Pressure_Pg,pageHandle), ATMO_ABILITY(Pressure_Pg, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Pressure_Pg,pageHandle), 1, ATMO_ABILITY(Pressure_Pg, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Pressure_Pg,pageHandle), 2, ATMO_ABILITY(Pressure_Pg, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Pressure_Pg,pageHandle), 3, ATMO_ABILITY(Pressure_Pg, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Pressure_Pg,pageHandle), 4, ATMO_ABILITY(Pressure_Pg, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Pressure_Pg, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Pressure_Pg_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Pressure_Pg_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Pressure_Pg,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t Air_Pg_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t Air_Pg_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(Air_Pg, x), ATMO_PROPERTY(Air_Pg, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t Air_Pg_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t Air_Pg_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Air_Pg_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Air_Pg_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Air_Pg_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Air_Pg_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(Air_Pg, pageHidden);
	config.textColor = ATMO_PROPERTY(Air_Pg, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(Air_Pg, topRightButtonEnabled),
    ATMO_PROPERTY(Air_Pg,bottomRightButtonEnabled), ATMO_PROPERTY(Air_Pg, topLeftButtonEnabled), ATMO_PROPERTY(Air_Pg, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(Air_Pg, x);
    config.x = ATMO_PROPERTY(Air_Pg, x);
    config.y = ATMO_PROPERTY(Air_Pg, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(Air_Pg, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(Air_Pg, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(Air_Pg, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(Air_Pg, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(Air_Pg, spanX);
	config.spanY = ATMO_PROPERTY(Air_Pg, spanY);
    config.title = ATMO_PROPERTY(Air_Pg, pageTitle);
    config.titleHidden = ATMO_PROPERTY(Air_Pg, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(Air_Pg, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(Air_Pg, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(Air_Pg, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(Air_Pg,pageHandle), ATMO_ABILITY(Air_Pg, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Air_Pg,pageHandle), 1, ATMO_ABILITY(Air_Pg, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Air_Pg,pageHandle), 2, ATMO_ABILITY(Air_Pg, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Air_Pg,pageHandle), 3, ATMO_ABILITY(Air_Pg, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(Air_Pg,pageHandle), 4, ATMO_ABILITY(Air_Pg, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(Air_Pg, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t Air_Pg_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t Air_Pg_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(Air_Pg,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t GetHumidStr_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	unsigned int humidity;
	ATMO_GetUnsignedInt(in, &humidity);
	char str[16];
	sprintf(str, "%u %%rh", humidity);
	ATMO_CreateValueString(out, str);
	return ATMO_Status_Success;
}


ATMO_Status_t RGBChar_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t RGBChar_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(RGBChar, instance),
		&ATMO_VARIABLE(RGBChar, bleServiceHandle), 
		ATMO_PROPERTY(RGBChar, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(RGBChar, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(RGBChar, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(RGBChar, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(RGBChar, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(RGBChar, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(RGBChar, writeDataType), ATMO_PROPERTY(RGBChar, readDataType), ATMO_PROPERTY(RGBChar, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(RGBChar, instance),
		&ATMO_VARIABLE(RGBChar, bleCharacteristicHandle), 
		ATMO_VARIABLE(RGBChar, bleServiceHandle), 
		ATMO_PROPERTY(RGBChar, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(RGBChar, instance),
		ATMO_VARIABLE(RGBChar, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(RGBChar, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t RGBChar_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(RGBChar, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(RGBChar, instance),
		ATMO_VARIABLE(RGBChar, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t RGBChar_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(RGBChar, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t RGBChar_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t RGBChar_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t FXAS21002Gyroscope_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t FXAS21002Gyroscope_setup(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_FXAS21002_Config_t config;
	config.address = ATMO_PROPERTY(FXAS21002Gyroscope, i2cAddress);
	config.i2cDriverInstance = ATMO_PROPERTY(FXAS21002Gyroscope, i2cInstance);
	config.samplingRate = ATMO_PROPERTY(FXAS21002Gyroscope, samplingRate);
	ATMO_FXAS21002_Init(&config);
	return ATMO_Status_Success;
}


ATMO_Status_t FXAS21002Gyroscope_setEnabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_FXAS21002_SetEnabled(true);
return ATMO_Status_Success;
}


ATMO_Status_t FXAS21002Gyroscope_setDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_FXAS21002_SetEnabled(false);
return ATMO_Status_Success;
}


ATMO_Status_t FXAS21002Gyroscope_setEnabledDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
bool enabled = false;
ATMO_GetBool(in, &enabled);
ATMO_FXAS21002_SetEnabled(enabled);
return ATMO_Status_Success;
}


ATMO_Status_t FXAS21002Gyroscope_getSensorData(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_FXAS21002_SensorData_t data;
	ATMO_3dFloatVector_t atmoVec;

	if(ATMO_FXAS21002_GetSensorData(&data) != ATMO_FXAS21002_Status_Success)
	{
		ATMO_CreateValueVoid(out);
		return ATMO_Status_Fail;
	}

	atmoVec.x = data.X;
	atmoVec.y = data.Y;
	atmoVec.z = data.Z;

	ATMO_CreateValue3dVectorFloat(out, &atmoVec);
	return ATMO_Status_Success;

}


ATMO_Status_t FXAS21002Gyroscope_getDpsX(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_FXAS21002_SensorData_t data;

	if(ATMO_FXAS21002_GetSensorData(&data) != ATMO_FXAS21002_Status_Success)
	{
		ATMO_CreateValueVoid(out);
		return ATMO_Status_Fail;
	}

	ATMO_CreateValueFloat(out, data.X);
	return ATMO_Status_Success;

}


ATMO_Status_t FXAS21002Gyroscope_getDpsY(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_FXAS21002_SensorData_t data;

	if(ATMO_FXAS21002_GetSensorData(&data) != ATMO_FXAS21002_Status_Success)
	{
		ATMO_CreateValueVoid(out);
		return ATMO_Status_Fail;
	}

	ATMO_CreateValueFloat(out, data.Y);
	return ATMO_Status_Success;

}


ATMO_Status_t FXAS21002Gyroscope_getDpsZ(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_FXAS21002_SensorData_t data;

	if(ATMO_FXAS21002_GetSensorData(&data) != ATMO_FXAS21002_Status_Success)
	{
		ATMO_CreateValueVoid(out);
		return ATMO_Status_Fail;
	}

	ATMO_CreateValueFloat(out, data.Z);
	return ATMO_Status_Success;

}


ATMO_Status_t GyroX_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroX_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(GyroX, instance),
		&ATMO_VARIABLE(GyroX, bleServiceHandle), 
		ATMO_PROPERTY(GyroX, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(GyroX, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(GyroX, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(GyroX, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(GyroX, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(GyroX, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(GyroX, writeDataType), ATMO_PROPERTY(GyroX, readDataType), ATMO_PROPERTY(GyroX, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(GyroX, instance),
		&ATMO_VARIABLE(GyroX, bleCharacteristicHandle), 
		ATMO_VARIABLE(GyroX, bleServiceHandle), 
		ATMO_PROPERTY(GyroX, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(GyroX, instance),
		ATMO_VARIABLE(GyroX, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(GyroX, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroX_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(GyroX, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(GyroX, instance),
		ATMO_VARIABLE(GyroX, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroX_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(GyroX, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroX_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroX_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroY_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroY_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(GyroY, instance),
		&ATMO_VARIABLE(GyroY, bleServiceHandle), 
		ATMO_PROPERTY(GyroY, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(GyroY, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(GyroY, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(GyroY, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(GyroY, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(GyroY, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(GyroY, writeDataType), ATMO_PROPERTY(GyroY, readDataType), ATMO_PROPERTY(GyroY, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(GyroY, instance),
		&ATMO_VARIABLE(GyroY, bleCharacteristicHandle), 
		ATMO_VARIABLE(GyroY, bleServiceHandle), 
		ATMO_PROPERTY(GyroY, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(GyroY, instance),
		ATMO_VARIABLE(GyroY, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(GyroY, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroY_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(GyroY, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(GyroY, instance),
		ATMO_VARIABLE(GyroY, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroY_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(GyroY, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroY_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroY_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroZ_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroZ_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(GyroZ, instance),
		&ATMO_VARIABLE(GyroZ, bleServiceHandle), 
		ATMO_PROPERTY(GyroZ, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(GyroZ, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(GyroZ, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(GyroZ, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(GyroZ, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(GyroZ, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(GyroZ, writeDataType), ATMO_PROPERTY(GyroZ, readDataType), ATMO_PROPERTY(GyroZ, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(GyroZ, instance),
		&ATMO_VARIABLE(GyroZ, bleCharacteristicHandle), 
		ATMO_VARIABLE(GyroZ, bleServiceHandle), 
		ATMO_PROPERTY(GyroZ, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(GyroZ, instance),
		ATMO_VARIABLE(GyroZ, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(GyroZ, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroZ_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(GyroZ, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(GyroZ, instance),
		ATMO_VARIABLE(GyroZ, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroZ_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(GyroZ, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t GyroZ_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t GyroZ_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelX_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelX_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(AccelX, instance),
		&ATMO_VARIABLE(AccelX, bleServiceHandle), 
		ATMO_PROPERTY(AccelX, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(AccelX, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(AccelX, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(AccelX, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(AccelX, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(AccelX, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(AccelX, writeDataType), ATMO_PROPERTY(AccelX, readDataType), ATMO_PROPERTY(AccelX, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(AccelX, instance),
		&ATMO_VARIABLE(AccelX, bleCharacteristicHandle), 
		ATMO_VARIABLE(AccelX, bleServiceHandle), 
		ATMO_PROPERTY(AccelX, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(AccelX, instance),
		ATMO_VARIABLE(AccelX, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(AccelX, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelX_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(AccelX, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(AccelX, instance),
		ATMO_VARIABLE(AccelX, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelX_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(AccelX, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelX_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelX_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelY_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelY_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(AccelY, instance),
		&ATMO_VARIABLE(AccelY, bleServiceHandle), 
		ATMO_PROPERTY(AccelY, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(AccelY, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(AccelY, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(AccelY, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(AccelY, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(AccelY, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(AccelY, writeDataType), ATMO_PROPERTY(AccelY, readDataType), ATMO_PROPERTY(AccelY, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(AccelY, instance),
		&ATMO_VARIABLE(AccelY, bleCharacteristicHandle), 
		ATMO_VARIABLE(AccelY, bleServiceHandle), 
		ATMO_PROPERTY(AccelY, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(AccelY, instance),
		ATMO_VARIABLE(AccelY, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(AccelY, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelY_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(AccelY, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(AccelY, instance),
		ATMO_VARIABLE(AccelY, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelY_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(AccelY, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelY_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelY_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelZ_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelZ_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(AccelZ, instance),
		&ATMO_VARIABLE(AccelZ, bleServiceHandle), 
		ATMO_PROPERTY(AccelZ, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(AccelZ, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(AccelZ, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(AccelZ, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(AccelZ, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(AccelZ, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(AccelZ, writeDataType), ATMO_PROPERTY(AccelZ, readDataType), ATMO_PROPERTY(AccelZ, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(AccelZ, instance),
		&ATMO_VARIABLE(AccelZ, bleCharacteristicHandle), 
		ATMO_VARIABLE(AccelZ, bleServiceHandle), 
		ATMO_PROPERTY(AccelZ, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(AccelZ, instance),
		ATMO_VARIABLE(AccelZ, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(AccelZ, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelZ_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(AccelZ, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(AccelZ, instance),
		ATMO_VARIABLE(AccelZ, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelZ_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(AccelZ, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t AccelZ_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AccelZ_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MagX_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MagX_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(MagX, instance),
		&ATMO_VARIABLE(MagX, bleServiceHandle), 
		ATMO_PROPERTY(MagX, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(MagX, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(MagX, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(MagX, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(MagX, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(MagX, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(MagX, writeDataType), ATMO_PROPERTY(MagX, readDataType), ATMO_PROPERTY(MagX, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(MagX, instance),
		&ATMO_VARIABLE(MagX, bleCharacteristicHandle), 
		ATMO_VARIABLE(MagX, bleServiceHandle), 
		ATMO_PROPERTY(MagX, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(MagX, instance),
		ATMO_VARIABLE(MagX, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(MagX, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t MagX_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(MagX, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(MagX, instance),
		ATMO_VARIABLE(MagX, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t MagX_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(MagX, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t MagX_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MagX_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MagY_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MagY_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(MagY, instance),
		&ATMO_VARIABLE(MagY, bleServiceHandle), 
		ATMO_PROPERTY(MagY, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(MagY, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(MagY, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(MagY, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(MagY, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(MagY, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(MagY, writeDataType), ATMO_PROPERTY(MagY, readDataType), ATMO_PROPERTY(MagY, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(MagY, instance),
		&ATMO_VARIABLE(MagY, bleCharacteristicHandle), 
		ATMO_VARIABLE(MagY, bleServiceHandle), 
		ATMO_PROPERTY(MagY, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(MagY, instance),
		ATMO_VARIABLE(MagY, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(MagY, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t MagY_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(MagY, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(MagY, instance),
		ATMO_VARIABLE(MagY, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t MagY_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(MagY, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t MagY_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MagY_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MagZ_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MagZ_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GATTSAddService(
		ATMO_PROPERTY(MagZ, instance),
		&ATMO_VARIABLE(MagZ, bleServiceHandle), 
		ATMO_PROPERTY(MagZ, bleServiceUuid));
	
	uint8_t property = 0;
	uint8_t permission = 0;
	
	property |= ATMO_PROPERTY(MagZ, read) ? ATMO_BLE_Property_Read : 0;
	property |= ATMO_PROPERTY(MagZ, write) ? ATMO_BLE_Property_Write : 0;
	property |= ATMO_PROPERTY(MagZ, notify) ? ATMO_BLE_Property_Notify : 0;

	permission |= ATMO_PROPERTY(MagZ, read) ? ATMO_BLE_Permission_Read : 0;
	permission |= ATMO_PROPERTY(MagZ, write) ? ATMO_BLE_Permission_Write : 0;

	ATMO_DATATYPE types[3] = {ATMO_PROPERTY(MagZ, writeDataType), ATMO_PROPERTY(MagZ, readDataType), ATMO_PROPERTY(MagZ, notifyDataType)};
	
	ATMO_BLE_GATTSAddCharacteristic(
		ATMO_PROPERTY(MagZ, instance),
		&ATMO_VARIABLE(MagZ, bleCharacteristicHandle), 
		ATMO_VARIABLE(MagZ, bleServiceHandle), 
		ATMO_PROPERTY(MagZ, bleCharacteristicUuid), 
		property, permission, ATMO_GetMaxValueSize(3, 64, types));
	
	ATMO_BLE_GATTSRegisterCharacteristicAbilityHandle(
		ATMO_PROPERTY(MagZ, instance),
		ATMO_VARIABLE(MagZ, bleCharacteristicHandle), 
		ATMO_BLE_Characteristic_Written, 
		ATMO_ABILITY(MagZ, written));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t MagZ_setValue(ATMO_Value_t *in, ATMO_Value_t *out) {

	
	// Convert to the desired write data type
	ATMO_Value_t convertedValue;
	ATMO_InitValue(&convertedValue);
	ATMO_CreateValueConverted(&convertedValue, ATMO_PROPERTY(MagZ, readDataType), in);

	ATMO_BLE_GATTSSetCharacteristic(
		ATMO_PROPERTY(MagZ, instance),
		ATMO_VARIABLE(MagZ, bleCharacteristicHandle),
		convertedValue.size, 
		(uint8_t *)convertedValue.data,
		NULL);
	
	ATMO_FreeValue(&convertedValue);
		
	return ATMO_Status_Success;
	
}


ATMO_Status_t MagZ_written(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueConverted(out, ATMO_PROPERTY(MagZ, writeDataType), in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t MagZ_subscibed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MagZ_unsubscribed(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TapCOuntPage_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t TapCOuntPage_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(TapCOuntPage, x), ATMO_PROPERTY(TapCOuntPage, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t TapCOuntPage_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t TapCOuntPage_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t TapCOuntPage_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t TapCOuntPage_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t TapCOuntPage_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t TapCOuntPage_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(TapCOuntPage, pageHidden);
	config.textColor = ATMO_PROPERTY(TapCOuntPage, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(TapCOuntPage, topRightButtonEnabled),
    ATMO_PROPERTY(TapCOuntPage,bottomRightButtonEnabled), ATMO_PROPERTY(TapCOuntPage, topLeftButtonEnabled), ATMO_PROPERTY(TapCOuntPage, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(TapCOuntPage, x);
    config.x = ATMO_PROPERTY(TapCOuntPage, x);
    config.y = ATMO_PROPERTY(TapCOuntPage, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(TapCOuntPage, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(TapCOuntPage, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(TapCOuntPage, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(TapCOuntPage, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(TapCOuntPage, spanX);
	config.spanY = ATMO_PROPERTY(TapCOuntPage, spanY);
    config.title = ATMO_PROPERTY(TapCOuntPage, pageTitle);
    config.titleHidden = ATMO_PROPERTY(TapCOuntPage, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(TapCOuntPage, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(TapCOuntPage, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(TapCOuntPage, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(TapCOuntPage,pageHandle), ATMO_ABILITY(TapCOuntPage, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(TapCOuntPage,pageHandle), 1, ATMO_ABILITY(TapCOuntPage, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(TapCOuntPage,pageHandle), 2, ATMO_ABILITY(TapCOuntPage, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(TapCOuntPage,pageHandle), 3, ATMO_ABILITY(TapCOuntPage, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(TapCOuntPage,pageHandle), 4, ATMO_ABILITY(TapCOuntPage, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(TapCOuntPage, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t TapCOuntPage_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t TapCOuntPage_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(TapCOuntPage,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t BacklightOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t BacklightOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(BacklightOnOff, x), ATMO_PROPERTY(BacklightOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t BacklightOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t BacklightOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BacklightOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BacklightOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BacklightOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(BacklightOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(BacklightOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(BacklightOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(BacklightOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(BacklightOnOff, topLeftButtonEnabled), ATMO_PROPERTY(BacklightOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(BacklightOnOff, x);
    config.y = ATMO_PROPERTY(BacklightOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(BacklightOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(BacklightOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(BacklightOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(BacklightOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(BacklightOnOff, spanX);
	config.spanY = ATMO_PROPERTY(BacklightOnOff, spanY);
    config.title = ATMO_PROPERTY(BacklightOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(BacklightOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(BacklightOnOff, persist), ATMO_PROPERTY(BacklightOnOff, differentStartup));
    ATMO_VARIABLE(BacklightOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(BacklightOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(BacklightOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(BacklightOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(BacklightOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(BacklightOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(BacklightOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(BacklightOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(BacklightOnOff,pageHandle), 1, ATMO_ABILITY(BacklightOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(BacklightOnOff,pageHandle), 2, ATMO_ABILITY(BacklightOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(BacklightOnOff,pageHandle), 3, ATMO_ABILITY(BacklightOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(BacklightOnOff,pageHandle), ATMO_ABILITY(BacklightOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(BacklightOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t BacklightOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(BacklightOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t BacklightOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(BacklightOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t BacklightOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t BacklightOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t BacklightOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t BacklightOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t SensorTagOnOff_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t SensorTagOnOff_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(SensorTagOnOff, x), ATMO_PROPERTY(SensorTagOnOff, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t SensorTagOnOff_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t SensorTagOnOff_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t SensorTagOnOff_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t SensorTagOnOff_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t SensorTagOnOff_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
    config.hidden = ATMO_PROPERTY(SensorTagOnOff, pageHidden);
    config.textColor = ATMO_PROPERTY(SensorTagOnOff, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(SensorTagOnOff, topRightButtonEnabled),
		ATMO_PROPERTY(SensorTagOnOff,bottomRightButtonEnabled), ATMO_PROPERTY(SensorTagOnOff, topLeftButtonEnabled), ATMO_PROPERTY(SensorTagOnOff, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(SensorTagOnOff, x);
    config.y = ATMO_PROPERTY(SensorTagOnOff, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(SensorTagOnOff, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(SensorTagOnOff, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(SensorTagOnOff, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(SensorTagOnOff, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(SensorTagOnOff, spanX);
	config.spanY = ATMO_PROPERTY(SensorTagOnOff, spanY);
    config.title = ATMO_PROPERTY(SensorTagOnOff, pageTitle);
    config.titleHidden = ATMO_PROPERTY(SensorTagOnOff, titleHidden);
    ATMO_UI_SELECTICON_Init(&config, 2, true, ATMO_PROPERTY(SensorTagOnOff, persist), ATMO_PROPERTY(SensorTagOnOff, differentStartup));
    ATMO_VARIABLE(SensorTagOnOff, pageHandle) = config.templateInstance;
    ATMO_UI_SELECTICON_SetIcon(config.templateInstance, ATMO_PROPERTY(SensorTagOnOff,icon));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 0, "Off", !ATMO_PROPERTY(SensorTagOnOff, initialValue));
    ATMO_UI_SELECTICON_SetOptionText(config.templateInstance, 1, "On", ATMO_PROPERTY(SensorTagOnOff, initialValue));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(SensorTagOnOff, offSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(SensorTagOnOff, onSet));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 0, ATMO_ABILITY(SensorTagOnOff, offSetStartup));
    ATMO_UI_SELECTICON_RegisterOptionSelectedStartupAbilityHandle(config.templateInstance, 1, ATMO_ABILITY(SensorTagOnOff, onSetStartup));
    ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(SensorTagOnOff,pageHandle), 1, ATMO_ABILITY(SensorTagOnOff, topRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(SensorTagOnOff,pageHandle), 2, ATMO_ABILITY(SensorTagOnOff, bottomRightButtonPressed));
	ATMO_UI_SELECTICON_RegisterButtonAbilityHandle(ATMO_VARIABLE(SensorTagOnOff,pageHandle), 3, ATMO_ABILITY(SensorTagOnOff, topLeftButtonPressed));
    ATMO_UI_SELECTICON_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(SensorTagOnOff,pageHandle), ATMO_ABILITY(SensorTagOnOff, onDisplayed));
    ATMO_UI_SELECTICON_OverlaySaved(ATMO_VARIABLE(SensorTagOnOff, pageHandle));
    return ATMO_Status_Success;
    
}


ATMO_Status_t SensorTagOnOff_setOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(SensorTagOnOff,pageHandle), 0, true);
    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t SensorTagOnOff_setOn(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_SELECTICON_SetOption(ATMO_VARIABLE(SensorTagOnOff,pageHandle), 0, false);
    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t SensorTagOnOff_offSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, false);
    return ATMO_Status_Success;
    
}


ATMO_Status_t SensorTagOnOff_onSet(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_CreateValueBool(out, true);
    return ATMO_Status_Success;
    
}


ATMO_Status_t SensorTagOnOff_offSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t SensorTagOnOff_onSetStartup(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AndroidTag_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t AndroidTag_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(AndroidTag, x), ATMO_PROPERTY(AndroidTag, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t AndroidTag_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t AndroidTag_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AndroidTag_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AndroidTag_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AndroidTag_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AndroidTag_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(AndroidTag, pageHidden);
	config.textColor = ATMO_PROPERTY(AndroidTag, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(AndroidTag, topRightButtonEnabled),
    ATMO_PROPERTY(AndroidTag,bottomRightButtonEnabled), ATMO_PROPERTY(AndroidTag, topLeftButtonEnabled), ATMO_PROPERTY(AndroidTag, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(AndroidTag, x);
    config.x = ATMO_PROPERTY(AndroidTag, x);
    config.y = ATMO_PROPERTY(AndroidTag, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(AndroidTag, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(AndroidTag, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(AndroidTag, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(AndroidTag, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(AndroidTag, spanX);
	config.spanY = ATMO_PROPERTY(AndroidTag, spanY);
    config.title = ATMO_PROPERTY(AndroidTag, pageTitle);
    config.titleHidden = ATMO_PROPERTY(AndroidTag, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(AndroidTag, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(AndroidTag, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(AndroidTag, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(AndroidTag,pageHandle), ATMO_ABILITY(AndroidTag, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(AndroidTag,pageHandle), 1, ATMO_ABILITY(AndroidTag, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(AndroidTag,pageHandle), 2, ATMO_ABILITY(AndroidTag, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(AndroidTag,pageHandle), 3, ATMO_ABILITY(AndroidTag, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(AndroidTag,pageHandle), 4, ATMO_ABILITY(AndroidTag, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(AndroidTag, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t AndroidTag_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t AndroidTag_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(AndroidTag,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t IOSTag_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t IOSTag_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(IOSTag, x), ATMO_PROPERTY(IOSTag, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t IOSTag_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t IOSTag_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t IOSTag_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t IOSTag_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t IOSTag_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t IOSTag_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(IOSTag, pageHidden);
	config.textColor = ATMO_PROPERTY(IOSTag, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(IOSTag, topRightButtonEnabled),
    ATMO_PROPERTY(IOSTag,bottomRightButtonEnabled), ATMO_PROPERTY(IOSTag, topLeftButtonEnabled), ATMO_PROPERTY(IOSTag, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(IOSTag, x);
    config.x = ATMO_PROPERTY(IOSTag, x);
    config.y = ATMO_PROPERTY(IOSTag, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(IOSTag, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(IOSTag, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(IOSTag, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(IOSTag, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(IOSTag, spanX);
	config.spanY = ATMO_PROPERTY(IOSTag, spanY);
    config.title = ATMO_PROPERTY(IOSTag, pageTitle);
    config.titleHidden = ATMO_PROPERTY(IOSTag, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(IOSTag, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(IOSTag, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(IOSTag, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(IOSTag,pageHandle), ATMO_ABILITY(IOSTag, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(IOSTag,pageHandle), 1, ATMO_ABILITY(IOSTag, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(IOSTag,pageHandle), 2, ATMO_ABILITY(IOSTag, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(IOSTag,pageHandle), 3, ATMO_ABILITY(IOSTag, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(IOSTag,pageHandle), 4, ATMO_ABILITY(IOSTag, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(IOSTag, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t IOSTag_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t IOSTag_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(IOSTag,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t RgbLedPage_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t RgbLedPage_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(RgbLedPage, x), ATMO_PROPERTY(RgbLedPage, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t RgbLedPage_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t RgbLedPage_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t RgbLedPage_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t RgbLedPage_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t RgbLedPage_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t RgbLedPage_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(RgbLedPage, pageHidden);
	config.textColor = ATMO_PROPERTY(RgbLedPage, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(RgbLedPage, topRightButtonEnabled),
    ATMO_PROPERTY(RgbLedPage,bottomRightButtonEnabled), ATMO_PROPERTY(RgbLedPage, topLeftButtonEnabled), ATMO_PROPERTY(RgbLedPage, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(RgbLedPage, x);
    config.x = ATMO_PROPERTY(RgbLedPage, x);
    config.y = ATMO_PROPERTY(RgbLedPage, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(RgbLedPage, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(RgbLedPage, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(RgbLedPage, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(RgbLedPage, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(RgbLedPage, spanX);
	config.spanY = ATMO_PROPERTY(RgbLedPage, spanY);
    config.title = ATMO_PROPERTY(RgbLedPage, pageTitle);
    config.titleHidden = ATMO_PROPERTY(RgbLedPage, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(RgbLedPage, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(RgbLedPage, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(RgbLedPage, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(RgbLedPage,pageHandle), ATMO_ABILITY(RgbLedPage, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(RgbLedPage,pageHandle), 1, ATMO_ABILITY(RgbLedPage, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(RgbLedPage,pageHandle), 2, ATMO_ABILITY(RgbLedPage, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(RgbLedPage,pageHandle), 3, ATMO_ABILITY(RgbLedPage, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(RgbLedPage,pageHandle), 4, ATMO_ABILITY(RgbLedPage, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(RgbLedPage, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t RgbLedPage_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t RgbLedPage_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(RgbLedPage,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t GetOffStr_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_CreateValueString(out, "Color: Off");
	return ATMO_Status_Success;
}


ATMO_Status_t ThrRebootReqPage_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t ThrRebootReqPage_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(ThrRebootReqPage, x), ATMO_PROPERTY(ThrRebootReqPage, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t ThrRebootReqPage_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t ThrRebootReqPage_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t ThrRebootReqPage_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t ThrRebootReqPage_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t ThrRebootReqPage_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t ThrRebootReqPage_setText(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_Value_t strVal;
    ATMO_InitValue(&strVal);
    ATMO_CreateValueConverted(&strVal, ATMO_DATATYPE_STRING, in);
    ATMO_UI_STATICTEXT_SetText(ATMO_VARIABLE(ThrRebootReqPage,pageHandle), strVal.data);
    ATMO_FreeValue(&strVal);
	return ATMO_Status_Success;
	
}


ATMO_Status_t ThrRebootReqPage_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(ThrRebootReqPage, pageHidden);
	config.textColor = ATMO_PROPERTY(ThrRebootReqPage, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(ThrRebootReqPage, topRightButtonEnabled),
		ATMO_PROPERTY(ThrRebootReqPage,bottomRightButtonEnabled), ATMO_PROPERTY(ThrRebootReqPage, topLeftButtonEnabled), ATMO_PROPERTY(ThrRebootReqPage, bottomLeftButtonEnabled));
    config.x = ATMO_PROPERTY(ThrRebootReqPage, x);
	config.y = ATMO_PROPERTY(ThrRebootReqPage, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(ThrRebootReqPage, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(ThrRebootReqPage, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(ThrRebootReqPage, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(ThrRebootReqPage, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(ThrRebootReqPage, spanX);
	config.spanY = ATMO_PROPERTY(ThrRebootReqPage, spanY);
    config.title = ATMO_PROPERTY(ThrRebootReqPage, pageTitle);
    config.titleHidden = ATMO_PROPERTY(ThrRebootReqPage, titleHidden);
	ATMO_UI_STATICTEXT_Init(&config);
	ATMO_VARIABLE(ThrRebootReqPage, pageHandle) = config.templateInstance;
    ATMO_UI_STATICTEXT_SetText(config.templateInstance, ATMO_PROPERTY(ThrRebootReqPage, text));
	ATMO_UI_STATICTEXT_SetTextSize(config.templateInstance, ATMO_PROPERTY(ThrRebootReqPage, fontSize));
	ATMO_UI_STATICTEXT_SetAlignment(config.templateInstance, ATMO_PROPERTY(ThrRebootReqPage, horizontalAlignment));
	ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(ThrRebootReqPage,pageHandle), 1, ATMO_ABILITY(ThrRebootReqPage, topRightButtonPressed));
	ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(ThrRebootReqPage,pageHandle), 2, ATMO_ABILITY(ThrRebootReqPage, bottomRightButtonPressed));
	ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(ThrRebootReqPage,pageHandle), 3, ATMO_ABILITY(ThrRebootReqPage, topLeftButtonPressed));
    ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(ThrRebootReqPage,pageHandle), 4, ATMO_ABILITY(ThrRebootReqPage, bottomLeftButtonPressed));
    
	if(!config.hidden)
	{
		ATMO_UI_STATICTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(ThrRebootReqPage,pageHandle), ATMO_ABILITY(ThrRebootReqPage, onDisplayed));
	}
    return ATMO_Status_Success;
    
}


ATMO_Status_t BleRebootReqPage_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t BleRebootReqPage_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(BleRebootReqPage, x), ATMO_PROPERTY(BleRebootReqPage, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t BleRebootReqPage_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BleRebootReqPage_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BleRebootReqPage_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BleRebootReqPage_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BleRebootReqPage_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t BleRebootReqPage_setText(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_Value_t strVal;
    ATMO_InitValue(&strVal);
    ATMO_CreateValueConverted(&strVal, ATMO_DATATYPE_STRING, in);
    ATMO_UI_STATICTEXT_SetText(ATMO_VARIABLE(BleRebootReqPage,pageHandle), strVal.data);
    ATMO_FreeValue(&strVal);
	return ATMO_Status_Success;
	
}


ATMO_Status_t BleRebootReqPage_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(BleRebootReqPage, pageHidden);
	config.textColor = ATMO_PROPERTY(BleRebootReqPage, textColor);
	config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(BleRebootReqPage, topRightButtonEnabled),
		ATMO_PROPERTY(BleRebootReqPage,bottomRightButtonEnabled), ATMO_PROPERTY(BleRebootReqPage, topLeftButtonEnabled), ATMO_PROPERTY(BleRebootReqPage, bottomLeftButtonEnabled));
    config.x = ATMO_PROPERTY(BleRebootReqPage, x);
	config.y = ATMO_PROPERTY(BleRebootReqPage, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(BleRebootReqPage, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(BleRebootReqPage, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(BleRebootReqPage, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(BleRebootReqPage, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(BleRebootReqPage, spanX);
	config.spanY = ATMO_PROPERTY(BleRebootReqPage, spanY);
    config.title = ATMO_PROPERTY(BleRebootReqPage, pageTitle);
    config.titleHidden = ATMO_PROPERTY(BleRebootReqPage, titleHidden);
	ATMO_UI_STATICTEXT_Init(&config);
	ATMO_VARIABLE(BleRebootReqPage, pageHandle) = config.templateInstance;
    ATMO_UI_STATICTEXT_SetText(config.templateInstance, ATMO_PROPERTY(BleRebootReqPage, text));
	ATMO_UI_STATICTEXT_SetTextSize(config.templateInstance, ATMO_PROPERTY(BleRebootReqPage, fontSize));
	ATMO_UI_STATICTEXT_SetAlignment(config.templateInstance, ATMO_PROPERTY(BleRebootReqPage, horizontalAlignment));
	ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(BleRebootReqPage,pageHandle), 1, ATMO_ABILITY(BleRebootReqPage, topRightButtonPressed));
	ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(BleRebootReqPage,pageHandle), 2, ATMO_ABILITY(BleRebootReqPage, bottomRightButtonPressed));
	ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(BleRebootReqPage,pageHandle), 3, ATMO_ABILITY(BleRebootReqPage, topLeftButtonPressed));
    ATMO_UI_STATICTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(BleRebootReqPage,pageHandle), 4, ATMO_ABILITY(BleRebootReqPage, bottomLeftButtonPressed));
    
	if(!config.hidden)
	{
		ATMO_UI_STATICTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(BleRebootReqPage,pageHandle), ATMO_ABILITY(BleRebootReqPage, onDisplayed));
	}
    return ATMO_Status_Success;
    
}


ATMO_Status_t GetMotionDetectStr_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_CreateValueString(out, "Detected");
	return ATMO_Status_Success;
}


ATMO_Status_t GetFreefallDetectStr_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_CreateValueString(out, "Detected");
	return ATMO_Status_Success;
}


ATMO_Status_t GetResetStr_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_CreateValueString(out, "Not Detected");
	return ATMO_Status_Success;
}


ATMO_Status_t MotionResetInterval_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t MotionResetInterval_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_INTERVAL_Handle_t intervalHandle;
    ATMO_INTERVAL_AddAbilityInterval(
		ATMO_PROPERTY(MotionResetInterval, instance), 
		ATMO_ABILITY(MotionResetInterval, interval), 
		ATMO_PROPERTY(MotionResetInterval, time), 
		&intervalHandle
	);
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t MotionResetInterval_interval(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t ENS210TemperatureHumidity_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t ENS210TemperatureHumidity_setup(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_ENS210_Config_t config;
	config.address = ATMO_PROPERTY(ENS210TemperatureHumidity, i2cAddress);
	config.i2cDriverInstance = ATMO_PROPERTY(ENS210TemperatureHumidity, i2cInstance);
	config.tempCalibrationOffset = ATMO_PROPERTY(ENS210TemperatureHumidity, tempCalibrationOffset);

	return ( ATMO_ENS210_Init(&config) == ATMO_ENS210_Status_Success ) ? ATMO_Status_Success : ATMO_Status_Fail;

}


ATMO_Status_t ENS210TemperatureHumidity_setEnabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_ENS210_SetEnabled(true);
return ATMO_Status_Success;
}


ATMO_Status_t ENS210TemperatureHumidity_setDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_ENS210_SetEnabled(false);
return ATMO_Status_Success;
}


ATMO_Status_t ENS210TemperatureHumidity_setEnabledDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
bool enabled = false;
ATMO_GetBool(in, &enabled);
ATMO_ENS210_SetEnabled(enabled);
return ATMO_Status_Success;
}


ATMO_Status_t ENS210TemperatureHumidity_readTemperature(ATMO_Value_t *in, ATMO_Value_t *out) {
    float tempC;
    
    if(ATMO_ENS210_GetTemperatureFloat(&tempC) == ATMO_ENS210_Status_Success)
    {
        ATMO_CreateValueFloat(out, tempC);
    }
    else
    {
        ATMO_CreateValueVoid(out);
    }
    
    return ATMO_Status_Success;
}


ATMO_Status_t ENS210TemperatureHumidity_readHumidity(ATMO_Value_t *in, ATMO_Value_t *out) {
    float humidityPct;

    if(ATMO_ENS210_GetHumidityFloat(&humidityPct) == ATMO_ENS210_Status_Success)
    {
        ATMO_CreateValueFloat(out, humidityPct);
    }
    else
    {
        ATMO_CreateValueVoid(out);
    }
    
    return ATMO_Status_Success;
}


ATMO_Status_t GetVersionFunc_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	char versionStr[64];
	ATMO_BLE_MacAddress_t macAddr;
	ATMO_BLE_GetMacAddress(0, &macAddr);
	
	sprintf(versionStr, "Ver: %s\nBranch: %s\nMac: %02X:%02X:%02X:%02X:%02X:%02X",
	ATMO_GLOBALS_GIT_HASH, ATMO_GLOBALS_GIT_BRANCH, macAddr.data[0],macAddr.data[1],macAddr.data[2],
	macAddr.data[3],macAddr.data[4],macAddr.data[5]);
	
	ATMO_CreateValueString(out, versionStr);
	return ATMO_Status_Success;
}


ATMO_Status_t GetCurrentColor_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	uint8_t color, brightness;
	RGB_Led_Get_State(&brightness, &color);
	ATMO_CreateValueUnsignedInt(out, color);
	return ATMO_Status_Success;
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_setup(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_FXOS8700_Config_t config;
	config.address = ATMO_PROPERTY(FXOS8700AccelerometerMagnetometer, i2cAddress);
	config.i2cDriverInstance = ATMO_PROPERTY(FXOS8700AccelerometerMagnetometer, i2cInstance);
	config.gpioDriverInstance = ATMO_PROPERTY(FXOS8700AccelerometerMagnetometer, gpioInstance);
	config.int1En = ATMO_PROPERTY(FXOS8700AccelerometerMagnetometer, interrupt1Enabled);
    config.int2En = ATMO_PROPERTY(FXOS8700AccelerometerMagnetometer, interrupt2Enabled);
    config.int1Pin = ATMO_PROPERTY(FXOS8700AccelerometerMagnetometer, interrupt1Gpio);
    config.int2Pin = ATMO_PROPERTY(FXOS8700AccelerometerMagnetometer, interrupt2Gpio);

    switch(ATMO_PROPERTY(FXOS8700AccelerometerMagnetometer, motionDetectType))
    {
        case FXOS8700_NoDetect:
        {
            config.freefallEnabled = false;
            config.motionEnabled = false;
            config.tapDetectionEnabled = false;
            break;
        }
        case FXOS8700_FreefallDetect:
        {
            config.freefallEnabled = true;
            config.motionEnabled = false;
            config.tapDetectionEnabled = false;
            break;
        }
        case FXOS8700_MotionDetect:
        {
            config.freefallEnabled = false;
            config.motionEnabled = true;
            config.tapDetectionEnabled = false;
            break;
        }
        case FXOS8700_TapDetect:
        {
            config.freefallEnabled = false;
            config.motionEnabled = false;
            config.tapDetectionEnabled = true;
            break; 
        }
        default:
        {
            config.freefallEnabled = false;
            config.motionEnabled = false;  
            config.tapDetectionEnabled = false;
            break;
        }
    }

    ATMO_FXOS8700_SetMotionDetectedAbilityHandle(ATMO_ABILITY(FXOS8700AccelerometerMagnetometer, detectMotion));
    ATMO_FXOS8700_SetFreefallDetectedAbilityHandle(ATMO_ABILITY(FXOS8700AccelerometerMagnetometer, detectFreefall));
    ATMO_FXOS8700_SetTapDetectedAbilityHandle(ATMO_ABILITY(FXOS8700AccelerometerMagnetometer, detectTap));
	ATMO_FXOS8700_Init(&config);

    return ATMO_Status_Success;
	
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_setEnabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_FXOS8700_SetEnabled(true);
return ATMO_Status_Success;
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_setDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
ATMO_FXOS8700_SetEnabled(false);
return ATMO_Status_Success;
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_setEnabledDisabled(ATMO_Value_t *in, ATMO_Value_t *out) {
bool enabled = false;
ATMO_GetBool(in, &enabled);
ATMO_FXOS8700_SetEnabled(enabled);
return ATMO_Status_Success;
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_getAccelData(ATMO_Value_t *in, ATMO_Value_t *out) {
    ATMO_3dFloatVector_t data;

    if( ATMO_FXOS8700_GetAccelData(&data) != ATMO_FXOS8700_Status_Success )
    {
        ATMO_CreateValueVoid(out);
        return ATMO_Status_Fail;
    }

    ATMO_CreateValue3dVectorFloat(out, &data);

    return ATMO_Status_Success;
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_getAccelX(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_3dFloatVector_t data;

	if(ATMO_FXOS8700_GetAccelData(&data) != ATMO_FXOS8700_Status_Success)
	{
		ATMO_CreateValueVoid(out);
		return ATMO_Status_Fail;
	}

	ATMO_CreateValueFloat(out, data.x);
	return ATMO_Status_Success;

}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_getAccelY(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_3dFloatVector_t data;

	if(ATMO_FXOS8700_GetAccelData(&data) != ATMO_FXOS8700_Status_Success)
	{
		ATMO_CreateValueVoid(out);
		return ATMO_Status_Fail;
	}

	ATMO_CreateValueFloat(out, data.y);
	return ATMO_Status_Success;

}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_getAccelZ(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_3dFloatVector_t data;

	if(ATMO_FXOS8700_GetAccelData(&data) != ATMO_FXOS8700_Status_Success)
	{
		ATMO_CreateValueVoid(out);
		return ATMO_Status_Fail;
	}

	ATMO_CreateValueFloat(out, data.z);
	return ATMO_Status_Success;

}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_getMagData(ATMO_Value_t *in, ATMO_Value_t *out) {
    ATMO_3dFloatVector_t data;

    if( ATMO_FXOS8700_GetMagData(&data) != ATMO_FXOS8700_Status_Success )
    {
        ATMO_CreateValueVoid(out);
        return ATMO_Status_Fail;
    }

    ATMO_CreateValue3dVectorFloat(out, &data);

    return ATMO_Status_Success;
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_getMagX(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_3dFloatVector_t data;

	if(ATMO_FXOS8700_GetMagData(&data) != ATMO_FXOS8700_Status_Success)
	{
		ATMO_CreateValueVoid(out);
		return ATMO_Status_Fail;
	}

	ATMO_CreateValueFloat(out, data.x);
	return ATMO_Status_Success;

}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_getMagY(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_3dFloatVector_t data;

	if(ATMO_FXOS8700_GetMagData(&data) != ATMO_FXOS8700_Status_Success)
	{
		ATMO_CreateValueVoid(out);
		return ATMO_Status_Fail;
	}

	ATMO_CreateValueFloat(out, data.y);
	return ATMO_Status_Success;

}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_getMagZ(ATMO_Value_t *in, ATMO_Value_t *out) {
	ATMO_3dFloatVector_t data;

	if(ATMO_FXOS8700_GetMagData(&data) != ATMO_FXOS8700_Status_Success)
	{
		ATMO_CreateValueVoid(out);
		return ATMO_Status_Fail;
	}

	ATMO_CreateValueFloat(out, data.z);
	return ATMO_Status_Success;

}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_detectTap(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;

}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_detectMotion(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;

}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_detectFreefall(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;

}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_enableFreefallDetection(ATMO_Value_t *in, ATMO_Value_t *out) {
if(ATMO_FXOS8700_EnableFreefallDetection() == ATMO_FXOS8700_Status_Success)
{
    return ATMO_Status_Success;
}

return ATMO_Status_Fail;
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_enableMotionDetection(ATMO_Value_t *in, ATMO_Value_t *out) {
if(ATMO_FXOS8700_EnableMotionDetection() == ATMO_FXOS8700_Status_Success)
{
    return ATMO_Status_Success;
}

return ATMO_Status_Fail;
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_enableTapDetection(ATMO_Value_t *in, ATMO_Value_t *out) {
if(ATMO_FXOS8700_EnableTapDetection() == ATMO_FXOS8700_Status_Success)
{
    return ATMO_Status_Success;
}

return ATMO_Status_Fail;
}


ATMO_Status_t FXOS8700AccelerometerMagnetometer_disableDetection(ATMO_Value_t *in, ATMO_Value_t *out) {
if(ATMO_FXOS8700_DisableAllDetection() == ATMO_FXOS8700_Status_Success)
{
    return ATMO_Status_Success;
}

return ATMO_Status_Fail;
}


ATMO_Status_t BLEConnection_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t BLEConnection_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_PairingCfg_t pairingCfg;
	pairingCfg.pairingKey = ATMO_PROPERTY(BLEConnection, pairingKey);
	pairingCfg.type = ATMO_PROPERTY(BLEConnection, pairingType);
	ATMO_BLE_GAPPairingCfg(ATMO_PROPERTY(BLEConnection, instance), &pairingCfg);

	ATMO_BLE_RegisterEventAbilityHandle(ATMO_PROPERTY(BLEConnection, instance), ATMO_BLE_EVENT_Connected, ATMO_ABILITY(BLEConnection, connected));
	ATMO_BLE_RegisterEventAbilityHandle(ATMO_PROPERTY(BLEConnection, instance), ATMO_BLE_EVENT_Disconnected, ATMO_ABILITY(BLEConnection, disconnected));
	ATMO_BLE_RegisterEventAbilityHandle(ATMO_PROPERTY(BLEConnection, instance), ATMO_BLE_EVENT_PairingRequested, ATMO_ABILITY(BLEConnection, pairingRequested));
	ATMO_BLE_RegisterEventAbilityHandle(ATMO_PROPERTY(BLEConnection, instance), ATMO_BLE_EVENT_PairingSuccess, ATMO_ABILITY(BLEConnection, pairingSucceeded));
	ATMO_BLE_RegisterEventAbilityHandle(ATMO_PROPERTY(BLEConnection, instance), ATMO_BLE_EVENT_PairingFailed, ATMO_ABILITY(BLEConnection, pairingFailed));
	
	return ATMO_Status_Success;
	
}


ATMO_Status_t BLEConnection_disconnect(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_BLE_GAPDisconnect(ATMO_PROPERTY(BLEConnection, instance));
	return ATMO_Status_Success;
	
}


ATMO_Status_t BLEConnection_connected(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BLEConnection_disconnected(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BLEConnection_pairingRequested(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_CreateValueCopy(out, in);
	return ATMO_Status_Success;
	
}


ATMO_Status_t BLEConnection_pairingSucceeded(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t BLEConnection_pairingFailed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingSuccess_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t PairingSuccess_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(PairingSuccess, x), ATMO_PROPERTY(PairingSuccess, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingSuccess_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t PairingSuccess_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingSuccess_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingSuccess_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingSuccess_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingSuccess_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(PairingSuccess, pageHidden);
	config.textColor = ATMO_PROPERTY(PairingSuccess, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(PairingSuccess, topRightButtonEnabled),
    ATMO_PROPERTY(PairingSuccess,bottomRightButtonEnabled), ATMO_PROPERTY(PairingSuccess, topLeftButtonEnabled), ATMO_PROPERTY(PairingSuccess, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(PairingSuccess, x);
    config.x = ATMO_PROPERTY(PairingSuccess, x);
    config.y = ATMO_PROPERTY(PairingSuccess, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(PairingSuccess, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(PairingSuccess, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(PairingSuccess, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(PairingSuccess, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(PairingSuccess, spanX);
	config.spanY = ATMO_PROPERTY(PairingSuccess, spanY);
    config.title = ATMO_PROPERTY(PairingSuccess, pageTitle);
    config.titleHidden = ATMO_PROPERTY(PairingSuccess, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(PairingSuccess, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(PairingSuccess, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(PairingSuccess, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(PairingSuccess,pageHandle), ATMO_ABILITY(PairingSuccess, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingSuccess,pageHandle), 1, ATMO_ABILITY(PairingSuccess, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingSuccess,pageHandle), 2, ATMO_ABILITY(PairingSuccess, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingSuccess,pageHandle), 3, ATMO_ABILITY(PairingSuccess, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingSuccess,pageHandle), 4, ATMO_ABILITY(PairingSuccess, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(PairingSuccess, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t PairingSuccess_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingSuccess_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(PairingSuccess,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t PairingFail_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t PairingFail_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(PairingFail, x), ATMO_PROPERTY(PairingFail, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingFail_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t PairingFail_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingFail_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingFail_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingFail_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingFail_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(PairingFail, pageHidden);
	config.textColor = ATMO_PROPERTY(PairingFail, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(PairingFail, topRightButtonEnabled),
    ATMO_PROPERTY(PairingFail,bottomRightButtonEnabled), ATMO_PROPERTY(PairingFail, topLeftButtonEnabled), ATMO_PROPERTY(PairingFail, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(PairingFail, x);
    config.x = ATMO_PROPERTY(PairingFail, x);
    config.y = ATMO_PROPERTY(PairingFail, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(PairingFail, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(PairingFail, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(PairingFail, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(PairingFail, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(PairingFail, spanX);
	config.spanY = ATMO_PROPERTY(PairingFail, spanY);
    config.title = ATMO_PROPERTY(PairingFail, pageTitle);
    config.titleHidden = ATMO_PROPERTY(PairingFail, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(PairingFail, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(PairingFail, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(PairingFail, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(PairingFail,pageHandle), ATMO_ABILITY(PairingFail, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingFail,pageHandle), 1, ATMO_ABILITY(PairingFail, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingFail,pageHandle), 2, ATMO_ABILITY(PairingFail, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingFail,pageHandle), 3, ATMO_ABILITY(PairingFail, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingFail,pageHandle), 4, ATMO_ABILITY(PairingFail, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(PairingFail, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t PairingFail_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingFail_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(PairingFail,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t PairingCode_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t PairingCode_displayPage(ATMO_Value_t *in, ATMO_Value_t *out) {

	ATMO_UI_Page_DisplayPageByCoord(ATMO_PROPERTY(PairingCode, x), ATMO_PROPERTY(PairingCode, y), false);
	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingCode_onDisplayed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
    
}


ATMO_Status_t PairingCode_topRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingCode_bottomRightButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingCode_topLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingCode_bottomLeftButtonPressed(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingCode_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    ATMO_UI_PAGE_Config_t config;
	config.hidden = ATMO_PROPERTY(PairingCode, pageHidden);
	config.textColor = ATMO_PROPERTY(PairingCode, textColor);
    config.activeButtons = ATMO_UI_Page_GetButtonMask(ATMO_PROPERTY(PairingCode, topRightButtonEnabled),
    ATMO_PROPERTY(PairingCode,bottomRightButtonEnabled), ATMO_PROPERTY(PairingCode, topLeftButtonEnabled), ATMO_PROPERTY(PairingCode, bottomLeftButtonEnabled));
	config.x = ATMO_PROPERTY(PairingCode, x);
    config.x = ATMO_PROPERTY(PairingCode, x);
    config.y = ATMO_PROPERTY(PairingCode, y);
	strncpy(config.topLeftButtonLabel, ATMO_PROPERTY(PairingCode, topLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.topRightButtonLabel, ATMO_PROPERTY(PairingCode, topRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomLeftButtonLabel, ATMO_PROPERTY(PairingCode, bottomLeftButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
	strncpy(config.bottomRightButtonLabel, ATMO_PROPERTY(PairingCode, bottomRightButtonLabel), ATMO_BUTTON_LABEL_MAXLEN);
    config.spanX = ATMO_PROPERTY(PairingCode, spanX);
	config.spanY = ATMO_PROPERTY(PairingCode, spanY);
    config.title = ATMO_PROPERTY(PairingCode, pageTitle);
    config.titleHidden = ATMO_PROPERTY(PairingCode, titleHidden);
	ATMO_UI_SINGLEICONTEXT_Init(&config);
	ATMO_VARIABLE(PairingCode, pageHandle) = config.templateInstance;
    ATMO_UI_SINGLEICONTEXT_SetMainText(config.templateInstance, ATMO_PROPERTY(PairingCode, label));
    ATMO_UI_SINGLEICONTEXT_SetIcon(config.templateInstance, ATMO_PROPERTY(PairingCode, icon));
    ATMO_UI_SINGLEICONTEXT_RegisterOnDisplayedAbilityHandle(ATMO_VARIABLE(PairingCode,pageHandle), ATMO_ABILITY(PairingCode, onDisplayed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingCode,pageHandle), 1, ATMO_ABILITY(PairingCode, topRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingCode,pageHandle), 2, ATMO_ABILITY(PairingCode, bottomRightButtonPressed));
	ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingCode,pageHandle), 3, ATMO_ABILITY(PairingCode, topLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterButtonAbilityHandle(ATMO_VARIABLE(PairingCode,pageHandle), 4, ATMO_ABILITY(PairingCode, bottomLeftButtonPressed));
    ATMO_UI_SINGLEICONTEXT_RegisterOnLeaveAbilityHandle(config.templateInstance, ATMO_ABILITY(PairingCode, onLeave));
	return ATMO_Status_Success;
    
}


ATMO_Status_t PairingCode_onLeave(ATMO_Value_t *in, ATMO_Value_t *out) {

	return ATMO_Status_Success;
	
}


ATMO_Status_t PairingCode_setLabel(ATMO_Value_t *in, ATMO_Value_t *out) {

    char label[32];
    if(ATMO_GetString(in, label, 32) == ATMO_Status_Success)
    {
        ATMO_UI_SINGLEICONTEXT_SetMainText(ATMO_VARIABLE(PairingCode,pageHandle), label);
    }
    else
    {
        return ATMO_Status_Fail;
    }

    return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkBacklight_trigger(ATMO_Value_t *in, ATMO_Value_t *out) {
	return ATMO_Status_Success;
}


ATMO_Status_t EmbeddedNxpRpkBacklight_setup(ATMO_Value_t *in, ATMO_Value_t *out) {

    Backlight_SetLevel(ATMO_PROPERTY(EmbeddedNxpRpkBacklight, initialSetting));
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkBacklight_setBacklightOff(ATMO_Value_t *in, ATMO_Value_t *out) {

    Backlight_SetLevel(BLIGHT_LEVEL_OFF);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkBacklight_setBacklightLow(ATMO_Value_t *in, ATMO_Value_t *out) {

    Backlight_SetLevel(BLIGHT_LEVEL_LOW);
	return ATMO_Status_Success;
	
}


ATMO_Status_t EmbeddedNxpRpkBacklight_setBacklightMedium(ATMO_Value_t *in, ATMO_Value_t *out) {

    Backlight_SetLevel(BLIGHT_LEVEL_MEDIUM);
	return ATMO_Status_Success;
    
}


ATMO_Status_t EmbeddedNxpRpkBacklight_setBacklightHigh(ATMO_Value_t *in, ATMO_Value_t *out) {

    Backlight_SetLevel(BLIGHT_LEVEL_HIGH);
	return ATMO_Status_Success;
	
}

//FOOTER START

//FOOTER END
