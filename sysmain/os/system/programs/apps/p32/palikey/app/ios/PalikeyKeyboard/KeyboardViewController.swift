import UIKit

class KeyboardViewController: UIInputViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        let key = UIButton(type: .system)
        key.setTitle("A", for: .normal)
        key.addTarget(self, action: #selector(tapKey), for: .touchUpInside)
        key.frame = CGRect(x: 20, y: 20, width: 60, height: 60)
        view.addSubview(key)
    }

    @objc func tapKey() {
        textDocumentProxy.insertText("A")
    }

    override func textWillChange(_ textInput: UITextInput?) {}
    override func textDidChange(_ textInput: UITextInput?) {}
}