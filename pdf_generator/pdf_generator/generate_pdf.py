#!/usr/bin/env python3

import jinja2
import pdfkit
from datetime import date

today = date.today().strftime("%d-%m-%Y")
pdf_filename = f"substation_scan_{today}.pdf"

tempate_loader = jinja2.FileSystemLoader('./')
template_env = jinja2.Environment(loader=tempate_loader)

template = template_env.get_template('template.html')
output_text = template.render()

config = pdfkit.configuration(wkhtmltopdf='/usr/bin/wkhtmltopdf')
options = {
    'orientation': 'Landscape',
    'page-size': 'A4',
}
pdfkit.from_string(output_text, pdf_filename, configuration=config, options=options)
