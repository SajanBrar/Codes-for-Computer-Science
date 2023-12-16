#!/usr/bin/env python
# coding: utf-8

# In[54]:


from selenium import webdriver
from selenium.webdriver.common.by import By
import time
# Initialize the WebDriver (in this example, we're using Chrome)
driver = webdriver.Chrome()

# Navigate to the w3schools web page
driver.get("https://www.w3schools.com/HTML/html_lists.asp")

ul = driver.find_element(By.CSS_SELECTOR, "ul")  # Change the selector accordingly

# Find all list items (LI) elements within the unordered list
list_items = ul.find_elements(By.TAG_NAME, "li")

# Get the number of list items
number_of_list_items = len(list_items)

print("Number of list items:", number_of_list_items)
time.sleep(50)

# Close the WebDriver when done
driver.quit()


# In[7]:


pip install selenium


# In[66]:


from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

# Replace these with your actual Instagram credentials
username = "aniketg.it.20@nitj.ac.in"
password = ""

# Initialize the WebDriver (in this example, we're using Chrome)
driver = webdriver.Chrome()

# Navigate to the Instagram login page
driver.get("https://leetcode.com/accounts/login/")

# Wait for a few seconds to ensure the page is fully loaded
time.sleep(2)

# Find the username input field and enter the username
username_field = driver.find_element(By.NAME, "login")
username_field.send_keys(username)

# Find the password input field and enter the password
password_field = driver.find_element(By.NAME, "password")
password_field.send_keys(password)

# Submit the form to log in
password_field.send_keys(Keys.RETURN)

# Wait for some time to allow the login process to complete
time.sleep(50)

# Optionally, you can add further actions or validations here, such as checking for successful login

# Close the WebDriver when done
driver.quit()


# In[64]:


from selenium import webdriver
from selenium.webdriver.common.keys import Keys

# Initialize the WebDriver (e.g., ChromeDriver)
driver = webdriver.Chrome()

# Open Google in the browser
driver.get("https://www.google.com")

# Define search queries
search_queries = ["C Programming"]

# Perform searches and verify results
for query in search_queries:
    search_box = driver.find_element(By.NAME, "q")
    search_box.clear()
    search_box.send_keys(query)
    search_box.send_keys(Keys.RETURN)

    # Add your verifications here, e.g., checking for specific URLs in the search results
time.sleep(40)
# Close the browser
driver.quit()


# In[32]:





# In[34]:


from selenium import webdriver

# Initialize the WebDriver (e.g., ChromeDriver)
driver = webdriver.Chrome()

# Navigate to the web page
driver.get("https://www.google.com")

# Find all elements on the page
elements = driver.find_elements_by_css_selector("*")

# Get the total number of elements
total_elements = len(elements)

# Print the total number of elements
print(f"Total number of elements on www.google.com: {total_elements}")

# Close the brows


# In[46]:


from selenium import webdriver

# Initialize the WebDriver (e.g., ChromeDriver)
driver = webdriver.Chrome()

# Navigate to the web page
driver.get("https://www.google.com")

# Find all elements on the page using a CSS selector
elements = driver.find_element(By.CSS_SELECTOR, "*") 
items = elements.find_elements(By.TAG_NAME, "script")
# Get the total number of elements
total_elements = len(items)

# Print the total number of elements
print(f"Total number of elements on www.google.com: {total_elements}")

# Close the browser
driver.quit()


# In[67]:


from selenium import webdriver
from selenium.webdriver.common.by import By

# Initialize the WebDriver (e.g., ChromeDriver)
driver = webdriver.Chrome()

# Navigate to the web page
driver.get("https://www.google.com")

# Find all script elements on the page
elements = driver.find_elements(By.TAG_NAME, "*")

# Get the total number of script elements
total_elements = len(elements)

# Print the total number of script elements
print(f"Total number of elements on www.google.com: {total_elements}")

# Close the browser
driver.quit()








# In[59]:


from selenium import webdriver

# Initialize the WebDriver (e.g., ChromeDriver)
driver = webdriver.Chrome()

# Navigate to a web page containing checkboxes and radio buttons
driver.get("http://127.0.0.1:5500/try.html")

# Select a checkbox
checkbox = driver.find_element(By.NAME, "comedy")
if not checkbox.is_selected():  # Check if the checkbox is not already selected
    checkbox.click()

# Select a radio button
radio_button = driver.find_element(By.ID, "lt20")
if not radio_button.is_selected():  # Check if the radio button is not already selected
    radio_button.click()
time.sleep(40)
# Close the browser
driver.quit()


# In[2]:


from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support
 
import expected_conditions as EC

def update_student_records():
    # Open the Excel file
    excel_file = open('C:\\Users\\Champs\\Desktop\\Students.xls', 'r')

    # Read the student records from the Excel file
    student_records = []
    for row in excel_file:
        row = row.strip()
        student_id, name, age, grade = row.split(',')
        student_records.append({
            'student_id': student_id,
            'name': name,
            'age': age,
            'grade': grade
        })

    # Close the Excel file
    excel_file.close()

    # Start the Selenium webdriver
    driver = webdriver.Chrome()

    # Open the web page that contains the student records table
    driver.get('http://localhost:8000/students')

    # Find the student records table
    student_records_table = driver.find_element_by_id('student-records-table')

    # Find the table rows
    table_rows = student_records_table.find_elements_by_tag_name('tr')

    # Update the student records
    for i, table_row in enumerate(table_rows):
        if i == 0:
            # Skip the header row
            continue

        # Find the student ID cell
        student_id_cell = table_row.find_element_by_tag_name('td')

        # Find the student name cell
        student_name_cell = student_id_cell.find_next_element_by_tag_name('td')

        # Find the student age cell
        student_age_cell = student_name_cell.find_next_element_by_tag_name('td')

        # Find the student grade cell
        student_grade_cell = student_age_cell.find_next_element_by_tag_name('td')

        # Find the student result cell
        student_result_cell = student_grade_cell.find_next_element_by_tag_name('td')

        # Get the student record from the Excel file
        student_record = next(record for record in student_records if record['student_id'] == student_id_cell.text)

        # Update the student name, age, and grade in the web page
        student_name_cell.clear()
        student_name_cell.send_keys(student_record['name'])

        student_age_cell.clear()
        student_age_cell.send_keys(student_record['age'])

        student_grade_cell.clear()
        student_grade_cell.send_keys(student_record['grade'])

        # Calculate the result (pass/fail)
        marks = int(student_record['grade'])
        result = 'Pass' if marks > 35 else 'Fail'

        # Update the student result in the web page
        student_result_cell.clear()
        student_result_cell.send_keys(result)

    # Submit the updated student records
    submit_button = driver.find_element_by_id('submit-button')
    submit_button.click()

    # Wait for the confirmation message to appear
    confirmation_message = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.ID, 'confirmation-message'))
    )

    # Print the confirmation message
    print(confirmation_message.text)

if __name__ == '__main__':
    update_student_records()


# In[ ]:




