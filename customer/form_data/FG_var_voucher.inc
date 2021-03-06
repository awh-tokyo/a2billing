<?php

/* vim: set expandtab tabstop=4 shiftwidth=4 softtabstop=4: */

/**
 * This file is part of A2Billing (http://www.a2billing.net/)
 *
 * A2Billing, Commercial Open Source Telecom Billing platform,   
 * powered by Star2billing S.L. <http://www.star2billing.com/>
 * 
 * @copyright   Copyright (C) 2004-2009 - Star2billing S.L. 
 * @author      Belaid Arezqui <areski@gmail.com>
 * @license     http://www.fsf.org/licensing/licenses/agpl-3.0.html
 * @package     A2Billing
 *
 * Software License Agreement (GNU Affero General Public License)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * 
**/



getpost_ifset(array('voucher'));


$HD_Form = new FormHandler("cc_voucher","Voucher");

$HD_Form -> FG_DEBUG = 0;

$HD_Form -> FG_VIEW_TABLE_WITDH = "65%";

$HD_Form -> AddViewElement(gettext("VOUCHER"), "voucher", "13%", "center", "sort");
$HD_Form -> AddViewElement(gettext("CREDIT"), "credit", "7%", "center", "sort");
$HD_Form -> AddViewElement(gettext(CURRENCY), "currency", "7%", "center", "sort");


$HD_Form -> FieldViewElement ('voucher, credit, currency');

$HD_Form -> FG_TABLE_CLAUSE = "usedcardnumber='".$_SESSION["pr_login"]."'";

$HD_Form -> CV_NO_FIELDS  = gettext("No vouchers have been used!");
$HD_Form -> CV_DISPLAY_LINE_TITLE_ABOVE_TABLE = false;
$HD_Form -> CV_TEXT_TITLE_ABOVE_TABLE = '';
$HD_Form -> CV_DISPLAY_FILTER_ABOVE_TABLE = false;
$HD_Form -> FG_EXPORT_CSV = false;

$HD_Form -> FG_EDITION = false;
$HD_Form -> FG_DELETION = false;
$HD_Form -> FG_ADDITION = false;

// Set the filter variables
$HD_Form -> FG_FILTER_APPLY = false;
$HD_Form -> FG_FILTERFIELD = 'voucher';
$HD_Form -> FG_FILTERFIELDNAME = 'voucher';

if (isset($filterprefix)  &&  (strlen($filterprefix)>0)){
	if (strlen($HD_Form -> FG_TABLE_CLAUSE)>0) $HD_Form -> FG_TABLE_CLAUSE.=" AND ";
	$HD_Form -> FG_TABLE_CLAUSE.="voucher like '$filterprefix%'";
}
